#include "buildme.c"

int main()
{
    first.input_path = "main.c";
    first.output_path = "main.exe";
    first.compiler_flags = "-MT -nologo -Od -Oi -Z7";
    first.linker_flags = "-opt:ref";

    BuildProgram();

    return 0;
}
