#include <stdlib.h>

typedef struct
{
    char run_flag;
    char *input_path;
    char *output_path;
    char *compiler_flags;
    char *linker_flags;
    
    char *run_string;
} First;

First first = {};

int scmp(char *a, char *b)
{
    for (int x = 0; a[x] == b[x]; ++x)
	if (!a[x] || ++x >= slen(a)) return 1;
    return 0;
}

int slen(char *str)
{
    int x;
    for (x = 0; str[x]; ++x);
    return x;
}

void copy(char *here, char *this)
{
    for (int x = 0; (here[x] = this[x]); ++x);
}

void copy_right(char *str1, char *str2)
{
    char *ptr = &str1[slen(str1)];
    copy(ptr, str2);
}

void copy_left(char *here, char *this)
{
    char *tmp = malloc(sizeof(here));
    copy(tmp, here);
    copy(here, this);
    copy_right(here, tmp);
    free(tmp);
}

void build_program()
{
    first.run_string = (char *) malloc(256);

    copy(first.run_string, "cl ");
    if (slen(first.compiler_flags)) {
	copy_right(first.run_string, first.compiler_flags);
	copy_right(first.run_string, " ");
    }
    copy_right(first.run_string, first.input_path);
    if (slen(first.linker_flags)) {
	copy_right(first.run_string, " /link ");
	copy_right(first.run_string, first.linker_flags);
    }
    copy_right(first.run_string, " /out:");
    copy_right(first.run_string, first.output_path);
    if (first.run_flag) {
	copy_right(first.run_string, " && ");
	copy_right(first.run_string, first.output_path);
    }

    system(first.run_string);
    free(first.run_string);
}
