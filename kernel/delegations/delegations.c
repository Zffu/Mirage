#include "./delegations.h"

#include "../../cpu/types.h"

#include "../../drivers/screen.h"

#include "../../lib/mem.h"
#include "../utils/str.h"

int kernelDelegationCount = 0;
DELEGATION_ENTRY* kernelDelegationRoot = 0;
DELEGATION_ENTRY* kernelDelegationCurr = 0;

DELEGATE* createDelegate(char* name, unsigned char level) {
    if(level == 0x00 && kernelDelegationCount > 0) {
        print("[");
        printWithColor("ERROR", RED_ON_WHITE);
        print("] Delegate ");
        print(name);
        print(" attempted to inherit absolute permissions\n");

        return -1;
    }

    u32 physical;
    DELEGATION_ENTRY* delegate = malloc(sizeof(DELEGATION_ENTRY), 1, &physical);

    delegate->name = name;
    delegate->level = level;
    delegate->next = 0;

    if(kernelDelegationCount == 0) {
        kernelDelegationRoot = delegate;
        kernelDelegationCurr = kernelDelegationRoot;
    }
    else {
        kernelDelegationCurr->next = delegate;
        kernelDelegationCurr = kernelDelegationCurr->next;
    }

    kernelDelegationCount++;

    return (DELEGATE*)delegate;
}

