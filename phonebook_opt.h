#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16



#ifdef DATA_STRUCTURE_OPTIMIZATION_SMALLER_SIZE

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct __PHONE_BOOK_RELATED_INFORMATIN {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} releated;
#endif

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
#ifdef DATA_STRUCTURE_OPTIMIZATION_SMALLER_SIZE
    releated *related_information;
#else
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
#endif
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;



entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
