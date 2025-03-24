#include "buildme.c"

void debug_build()
{
    first.compiler_flags = "-Od -Oi -Z7 -Wno-writable-strings";
    first.linker_flags = "";

    BuildProgram();
}

void release_build()
{
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
    if (argc < 2) {
	system("echo \"usage: test [-debug|-release]\"");
    }

    first.input_path = "hello.c";
    first.output_path = "hello.exe";

    if (scmp(argv[1], "-release")) {
	system("echo release");
	release_build();
    }
    if (scmp(argv[1], "-debug")) {
	system("echo debug");
	debug_build();
    }

    return 0;
}
