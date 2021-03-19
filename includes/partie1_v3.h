#ifndef PARTIE1_V3_H
#define PARTIE1_V3_H

#define MAXLEN 8
#define MAXMOTS 1000

typedef unsigned long size_t;

typedef struct 
{
    size_t len;
    size_t lineNumber;
    char * signature;
    char * self;
}T_mot;

char * signature(char * s);
void sortString(char * s);
char * removeDuplicates(char * s);
void printAnagrams(char * filename);
int compare(const void * a, const void * b);
int checkAnagram(char * a, char * b);

#endif