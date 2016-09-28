#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_opt_2.h"

static level1_compare first_char_link[52] = {
    {'A', '\0'},
    {'B', '\0'},
    {'C', '\0'},
    {'D', '\0'},
    {'E', '\0'},
    {'F', '\0'},
    {'G', '\0'},
    {'H', '\0'},
    {'I', '\0'},
    {'J', '\0'},
    {'K', '\0'},
    {'L', '\0'},
    {'M', '\0'},
    {'N', '\0'},
    {'O', '\0'},
    {'P', '\0'},
    {'Q', '\0'},
    {'R', '\0'},
    {'S', '\0'},
    {'T', '\0'},
    {'U', '\0'},
    {'V', '\0'},
    {'W', '\0'},
    {'X', '\0'},
    {'Y', '\0'},
    {'Z', '\0'},
    {'a', '\0'},
    {'b', '\0'},
    {'c', '\0'},
    {'d', '\0'},
    {'e', '\0'},
    {'f', '\0'},
    {'g', '\0'},
    {'h', '\0'},
    {'i', '\0'},
    {'j', '\0'},
    {'k', '\0'},
    {'l', '\0'},
    {'m', '\0'},
    {'n', '\0'},
    {'o', '\0'},
    {'p', '\0'},
    {'q', '\0'},
    {'r', '\0'},
    {'s', '\0'},
    {'t', '\0'},
    {'u', '\0'},
    {'v', '\0'},
    {'w', '\0'},
    {'x', '\0'},
    {'y', '\0'},
    {'z', '\0'}
};

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    unsigned char index = 0;

    for(index = 0; index < 52; index++) {
        //printf("first_char_link[index].link : %p\n", first_char_link[index].link);
        if(lastName[0] == first_char_link[index].first_char_of_name)
            break;
    }
    pHead = first_char_link[index].link;
    //printf("first_char_link[index].link : %p\n", first_char_link[index].link);
    while (pHead != '\0') {
        //printf("pHead->lastName : %s\n", pHead->lastName);
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{
    unsigned char index = 0;
    entry * level1_link = '\0';

    if (('A' <= lastName[0]) && (lastName[0] <= 'Z')) {
        index = lastName[0] - 'A';
    } else if (('a' <= lastName[0]) && (lastName[0] <= 'z')) {
        index = lastName[0] - 'a';
        index += 26;
    }

    //printf(" lastName : %s\n first_char_link[index].first_char_of_name : %c\n", lastName, first_char_link[index].first_char_of_name);
    //printf("index : %d\n", index);

    if(lastName[0] == first_char_link[index].first_char_of_name)
        level1_link = first_char_link[index].link;

    if (first_char_link[index].link == '\0') {
        e->pNext = first_char_link[index].link = (entry *) malloc(sizeof(entry));
    } else {
        while (level1_link->pNext != '\0')
            level1_link = level1_link->pNext;
        e->pNext = level1_link->pNext = (entry *) malloc(sizeof(entry));
    }

    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = '\0';

    return e;
}
