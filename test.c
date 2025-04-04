#include "buildme.c"
#include <stdio.h>

void debug_build()
{
    printf("debug build\n");
    
    first.compiler_flags = "-Od -Oi -Z7";
    first.linker_flags   = "";

    build_program();
}

void release_build()
{
    printf("release build\n");
    
    first.compiler_flags = "-O2 -Wno-writable-strings";
    first.linker_flags   = "";
    
    build_program();
}

void custom_build()
{
    printf("custom build\n");

    first.compiler_flags = "";
    first.linker_flags   = "";

    first.run_string = malloc(256);
    first.run_string = "";

    copy(first.run_string, first.compiler_flags);    
    copy_right(first.run_string, first.input_path);
    copy_right(first.run_string, first.linker_flags);
    copy_right(first.run_string, " /out:");
    copy_right(first.run_string, first.output_path);

    copy_left(first.run_string, "cl ");
    printf("%s\n", first.run_string);
    
    system(first.run_string);
    free(first.run_string);
}

int main(int argc, char **argv)
{    
    first.input_path = "hello.c";
    first.output_path = "hello.exe";
    first.run_flag = 0;

    if (argc < 2) {
	debug_build();
    }

    if (scmp(argv[1], "-release")) {
	release_build();
    }
    if (scmp(argv[1], "-debug")) {
	debug_build();
    }
    if (scmp(argv[1], "-run")) {
	first.run_flag = 1;
	debug_build();
    }
    if (scmp(argv[1], "-custom")) {
	custom_build();
    }

    return 0;
}
