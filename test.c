#include "buildme.c"

int main()
{
    first.input_path = "main.c";
    first.output_path = "main.exe";
    first.compiler_flags = "";
    first.linker_flags = "";
    
    BuildProgram();

    return 0;
}
