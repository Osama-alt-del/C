#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// =================Node and headTaili structs=====================
struct Node {
    struct Node* next; // next pointer
    struct Node* back; // back pointer
    int data; // this is the  data that the element contains
};

struct HeadTail { 
    struct Node* head; // this way, when they are NULL at the start, we can still access "headTail" and therefore changethem 
    struct Node* tail; // we won't get segfault by first trying to access a NULL memory address
};


// ================Functions==================

struct Node* createNode(int value);

// Insert at end O(1) with tail pointer
void appendNode(struct HeadTail* headTail_p, struct Node* newNode_p);

// Add to the start O(1)
void prependNode(struct HeadTail* headTail_p, struct Node* newNode_p);

// Print (O(N))
void printList(struct HeadTail* headTail_p);


// ===Remove===
void removeEnd(struct HeadTail* headTail_p);

void removeStart(struct HeadTail* headTail_p);

void freeAll(struct HeadTail* headTail_p);

#endif

