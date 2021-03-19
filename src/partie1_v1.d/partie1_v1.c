#include "../../includes/partie1_v1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMaxAndNumberOf(char * filename)
{
    FILE * f = fopen(filename, "r");
    if (!f)
    {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    static int counter[8];

    ssize_t read;
    size_t len = 0;
    char * line = NULL;
    int max = 0;
    while ((read = getline(&line, &len, f)) != -1)
    {
        int lineSize = strlen(line) - 1;
        if (lineSize < 9)
            ++counter[lineSize - 1];
        if (lineSize > max)
            max = lineSize;
    }

    fclose(f);
    if (line)
        free(line);

    printf("Le plus grand mot du dictionnaire a une taille de %d\n", max);
    for (int i = 0; i < 8; ++i)
        printf("Il y a %d mots de taille %d\n", counter[i], i + 1);
}