// I will use this to test the linked list file that I have made

#include "linkedList.h"

int main() { 
    // Must first create a head and a tail struct
    struct HeadTail headTail = {NULL, NULL};

    prependNode(&headTail, createNode(8));
    
    appendNode(&headTail, createNode(5));
    appendNode(&headTail, createNode(3));
    appendNode(&headTail, createNode(1));

    prependNode(&headTail, createNode(0));

    printList(&headTail);

   

    freeAll(&headTail);
    
    return 0;
}

