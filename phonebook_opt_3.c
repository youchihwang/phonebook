#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_3.h"

//
// create a array that strcuture has two member of letter, link
// The first character of the name on the dictionary has only little case name.
static level1_compare first_char_link[26] = {
    {'a', NULL, NULL},
    {'b', NULL, NULL},
    {'c', NULL, NULL},
    {'d', NULL, NULL},
    {'e', NULL, NULL},
    {'f', NULL, NULL},
    {'g', NULL, NULL},
    {'h', NULL, NULL},
    {'i', NULL, NULL},
    {'j', NULL, NULL},
    {'k', NULL, NULL},
    {'l', NULL, NULL},
    {'m', NULL, NULL},
    {'n', NULL, NULL},
    {'o', NULL, NULL},
    {'p', NULL, NULL},
    {'q', NULL, NULL},
    {'r', NULL, NULL},
    {'s', NULL, NULL},
    {'t', NULL, NULL},
    {'u', NULL, NULL},
    {'v', NULL, NULL},
    {'w', NULL, NULL},
    {'x', NULL, NULL},
    {'y', NULL, NULL},
    {'z', NULL, NULL}
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

    //printf(" lastName : %s\n first_char_link[index].first_char_of_name : %c\n", lastName, first_char_link[index].first_char_of_name);

    //
    // if the the first character of the name equal some index of bucket then assign link.
    //
    if(lastName[0] == first_char_link[index].first_char_of_name)
        level1_link = first_char_link[index].link;

    if (first_char_link[index].link != NULL) {
        level1_link = first_char_link[0].the_last_node; // insert new name to the last node
        e->pNext = level1_link->pNext = (entry *) malloc(sizeof(entry));
    } else {
        e->pNext = first_char_link[index].link = (entry *) malloc(sizeof(entry));
    }

    first_char_link[0].the_last_node = e->pNext; // update the last node position

    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
