#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
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

void
string_concat(char* str1, char* str2)
{
    char *tmp = (char *) malloc(strlen(str1) + strlen(str2));
    copy(tmp, str1);
    char *ptr = &tmp[strlen(str1)];
    copy(ptr, str2);
    *str1 = *(char *) malloc(strlen(tmp));
    copy(str1, tmp);
}

void
string_concat_first(char* str1, char* str2)
{
    *str1 = *(char *) malloc(strlen(str2));
    copy(str1, str2);
}

void
BuildProgram()
{
    char *run_string = (char *) malloc(1024);
    
    string_concat_first(run_string, "clang-cl ");
    string_concat(run_string, first.compiler_flags);
    string_concat(run_string, " ");
    string_concat(run_string, first.input_path);
    string_concat(run_string, " -o ");
    string_concat(run_string, first.output_path);
    string_concat(run_string, " /link ");
    string_concat(run_string, first.linker_flags);

    system(run_string);
}
