#include <stdlib.h>

typedef struct
{
    char run_flag;
    char *input_path;
    char *output_path;
    char *compiler_flags;
    char *linker_flags;
} First;

First first = {};

void
copy(char *a, char *b)
{
    for (int x = 0; (a[x] = b[x]); ++x);
}

int
slen(char *str)
{
    int x;
    for (x = 0; str[x] != '\0'; ++x);
    return x;
}

void
concat(char* str1, char* str2)
{
    char *ptr = &str1[slen(str1)];
    copy(ptr, str2);
}

void
BuildProgram()
{
    char *run_string = (char *) malloc(256);

    copy(run_string, "clang-cl ");
    if (slen(first.compiler_flags)) {
	concat(run_string, first.compiler_flags);
	concat(run_string, " ");
    }
    concat(run_string, first.input_path);
    concat(run_string, " -o ");
    concat(run_string, first.output_path);
    if (slen(first.linker_flags)) {
	concat(run_string, " /link ");
	concat(run_string, first.linker_flags);
    }
    if (first.run_flag == 1) {
	concat(run_string, " && ");
	concat(run_string, first.output_path);
    }

    system(run_string);
    free(run_string);
}
