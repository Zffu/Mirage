#ifndef KERNEL_DELEGATIONS
#define KERNEL_DELEGATIONS

typedef struct DELEGATE {

    char* name;
    unsigned char level;

} DELEGATE;

typedef struct DELEGATION_ENTRY {

    char* name;
    unsigned char level;

    struct DELEGATION_ENTRY* next;

} DELEGATION_ENTRY;

DELEGATE* createDelegate(char* name, unsigned char level);

DELEGATE* getMainDelegate();
int getDelegateCount();

#endif