#include "buildme.c"
#include <stdio.h>

void debug_build()
{
    printf("debug build\n");
    
    first.compiler_flags = "-Od -Oi -Z7 -Wno-writable-strings";
    first.linker_flags = "";

    BuildProgram();
}

void release_build()
{
    printf("release build\n");
    
    first.compiler_flags = "-O2 -Wno-writable-strings";
    first.linker_flags = "";
    
    BuildProgram();
}

int scmp(char *a, char *b)
{
    for (int x = 0; a[x] == b[x]; ++x)
	if (!a[x] || ++x >= slen(a)) return 1;
    return 0;
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

    return 0;
}
