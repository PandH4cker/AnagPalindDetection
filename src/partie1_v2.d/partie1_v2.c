#include "../../includes/partie1_v2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char * inverse(const char * s)
{
    size_t len = strlen(s);
    
    char * sCopy = malloc(strlen(s) + 1);

    strcpy(sCopy, s);

    for (int i = 0, j=len-1; i < j; ++i, --j)
        swap(&sCopy[i], &sCopy[j]);

    sCopy[len] = 0;
    return sCopy;
}

void printPalindromes(char * filename)
{
    FILE * f = fopen(filename, "r");
    if (!f)
    {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    ssize_t read;
    size_t len = 0;
    char * line = NULL;
    char * reversed = NULL;
    while ((read = getline(&line, &len, f)) != -1)
    {
        line[read - 1] = 0;
        reversed = inverse(line);

        if (strcmp(line, reversed) == 0)
            printf("%s\n", line);

        free(reversed);
    }

    fclose(f);
    if (line)
        free(line);
}