#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_opt_2.h"

//
// create a array that strcuture has two member of letter, link
// The first character of the name on the dictionary has only little case name.
static level1_compare first_char_link[26] = {
    {'a', NULL},
    {'b', NULL},
    {'c', NULL},
    {'d', NULL},
    {'e', NULL},
    {'f', NULL},
    {'g', NULL},
    {'h', NULL},
    {'i', NULL},
    {'j', NULL},
    {'k', NULL},
    {'l', NULL},
    {'m', NULL},
    {'n', NULL},
    {'o', NULL},
    {'p', NULL},
    {'q', NULL},
    {'r', NULL},
    {'s', NULL},
    {'t', NULL},
    {'u', NULL},
    {'v', NULL},
    {'w', NULL},
    {'x', NULL},
    {'y', NULL},
    {'z', NULL}
};

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    unsigned char index = 0;

    for(index = 0; index < 26; index++) {
        //printf("first_char_link[index].link : %p\n", first_char_link[index].link);
        if(lastName[0] == first_char_link[index].first_char_of_name)
            break;
    }
    pHead = first_char_link[index].link;
    //printf("first_char_link[index].link : %p\n", first_char_link[index].link);
    while (pHead != NULL) {
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
    entry * level1_link = NULL;

    index = lastName[0] - 'a'; // bucket array index

    //printf("index : %d\n", index);
    //printf(" lastName : %s\n first_char_link[index].first_char_of_name : %c\n", lastName, first_char_link[index].first_char_of_name);

    //
    // if the the first character of the name equal some index of bucket then assign link.
    //
    if(lastName[0] == first_char_link[index].first_char_of_name)
        level1_link = first_char_link[index].link;

    if (first_char_link[index].link != NULL) {
        while (level1_link->pNext != NULL) {
            level1_link = level1_link->pNext;
        }
        e->pNext = level1_link->pNext = (entry *) malloc(sizeof(entry));
    } else {
        e->pNext = first_char_link[index].link = (entry *) malloc(sizeof(entry));
    }

    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
