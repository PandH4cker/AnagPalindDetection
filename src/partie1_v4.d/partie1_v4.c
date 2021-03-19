#include "../../includes/partie1_v3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char * s)
{
   int c, d = 0, length;
   char *pointer, *result, ch;

   length = strlen(s);
   result = (char*)malloc(length+1);
   pointer = s;

   for (ch = 'a' ; ch <= 'z' ; ++ch)
   {
      for (c = 0 ; c < length ; ++c)
      {
         if (*pointer == ch)
         {
            *(result+d) = *pointer;
            d++;
         }
         pointer++;
      }
      pointer = s;
   }
   *(result+d) = '\0';

   strcpy(s, result);
   free(result);
}

char * removeDuplicates(char * s)
{
    size_t n = strlen(s) + 1;
    int index = 0;

    for (int i = 0; i < n; ++i)
    {
        int j;
        for (j = 0; j < i; ++j)
            if (s[i] == s[j]) break;
        if (j == i)
            s[index++] = s[i];
    }
    return s;
}

char * signature(char * s)
{
    char * str = calloc(1, strlen(s) + 1);
    strcpy(str, s);
    sortString(str);
    //str = removeDuplicates(str);
    return str;
}

int compare(const void * a, const void * b)
{
    T_mot * m1 = (T_mot *)a;
    T_mot * m2 = (T_mot *)b;
    return strcmp(m1->signature, m2->signature);
}

int checkAnagram(char * a, char * b)
{
    int first[26] = {0}, second[26] = {0}, c = 0;

    while(a[c] != '\0')
    {
        first[a[c] - 'a']++;
        ++c;
    }
    
    c = 0;

    while(b[c] != '\0')
    {
        second[b[c] - 'a']++;
        ++c;
    }

    for (c = 0; c < 26; ++c)
        if (first[c] != second[c])
            return 0;
    return 1;
}

void printAnagrams(char * filename)
{
    FILE * f = fopen(filename, "r");
    if (!f)
    {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    ssize_t read;
    size_t len = 0;
    size_t lineNumber = 0;
    char * line = NULL;
    T_mot tabMots[MAXMOTS];
    while ((read = getline(&line, &len, f)) != -1)
    {
        line[read - 1] = 0;
        tabMots[lineNumber].self = calloc(1, strlen(line) + 1);
        strcpy(tabMots[lineNumber].self, line);

        tabMots[lineNumber].lineNumber = lineNumber;
        tabMots[lineNumber].len = strlen(line);
        tabMots[lineNumber].signature = signature(line);

        if (++lineNumber == MAXMOTS) break;
    }

    qsort(tabMots, MAXMOTS, sizeof(T_mot), compare);

    for (int i = 0; i < MAXMOTS; ++i)
    {
        printf("%s:\n", tabMots[i].self);
        for (int j = 0; j < MAXMOTS; ++j)
            if (checkAnagram(tabMots[i].signature, tabMots[j].signature))
                printf("\t%s\n", tabMots[j].self);
    }
    

    fclose(f);
    if (line)
        free(line);
    for (int i = 0; i < MAXMOTS; ++i)
    {
        free(tabMots[i].self);
        free(tabMots[i].signature);
    }
}