#include <stdlib.h>

// TODO(alex-haley): have some ideas on how to make concatinations faster
// right now im doing a lot of string copying by character, so its O(n)
// or even O(n2) and not really fast, so what we can do instead is to create
// string struct that would contain string itself and integer that would
// determine the size of that string, so when we will copy one string to
// another, we will just copy the memory block which size we have inside
// string struct
// doing this will free us from always going throw each string multiple times,
// i expect with this memory blocks we should go through each string just
// once, to determine size of this string.

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

int scmp(char *a, char *b)
{
    for (int x = 0; a[x] == b[x]; ++x)
	if (!a[x] || ++x >= slen(a)) return 1;
    return 0;
}

void
BuildProgram()
{
    char *run_string = (char *) malloc(256);

    copy(run_string, "cd ../build && ");
    concat(run_string, "cl ");
    if (slen(first.compiler_flags)) {
	concat(run_string, first.compiler_flags);
	concat(run_string, " ");
    }
    concat(run_string, first.input_path);
    if (slen(first.linker_flags)) {
	concat(run_string, " /link ");
	concat(run_string, first.linker_flags);
    }
    concat(run_string, " /out:");
    concat(run_string, first.output_path);
    if (first.run_flag) {
	concat(run_string, " && ");
	concat(run_string, first.output_path);
    }
    concat(run_string, " && cd ../code");

    system(run_string);
    free(run_string);
}
