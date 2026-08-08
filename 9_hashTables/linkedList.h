// This is a header file for the linked list code that I wrote, so that I can use it whenever I want
// maybe I should split into a c file and a h file so that I can speed up compile time...
// But it's not like I have an object? Maybe it can still work. I need to look it up.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

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

struct Node* createNode(int value) { 
    struct Node* i = (struct Node*) malloc(sizeof(struct Node));
    if (i == NULL){
         printf("[Error] createNode(): メモリーの確保に失敗しました\n");
        struct Node* j;
        return  j; // return the memory of a null node 
    }
    
    i->next = NULL;
    i->back = NULL;
    i->data = value;
    return i; // we dynamically allocate the memory in the heap and then we return that pointer.
}

// Insert at end O(1) with tail pointer
void appendNode(struct HeadTail* headTail_p, struct Node* newNode_p) { 
    // checking if tail is NULL
    if (headTail_p->tail == NULL) { 
        headTail_p->tail = newNode_p; // the new node is now the tail of the linked list
        headTail_p->head = newNode_p; // since it's empty the head also points to thew newNode
        return;
    }
    headTail_p->tail->next = newNode_p; // you now point to the newNode
    newNode_p->back = headTail_p->tail; // back of new is old tail (add to end)
    headTail_p->tail = newNode_p; // newNode is now the tail
}

// Add to the start O(1)
void prependNode(struct HeadTail* headTail_p, struct Node* newNode_p) { 
    // checking if head is NULL
    if (headTail_p->head == NULL) { 
        headTail_p->head = newNode_p; // the new node is now the head
        headTail_p->tail = newNode_p;
        return;
    }
    newNode_p->next = headTail_p->head; // newNode points to head
    headTail_p->head->back = newNode_p; // old head points back to new
    headTail_p->head = newNode_p; // newNode is now the head
}

// Print (O(N))
void printList(struct HeadTail* headTail_p) {
    if (headTail_p->head == NULL && headTail_p->tail == NULL) { 
        return; // don't do anything because it's already an empty list
    }

    struct Node* node_p = headTail_p->head;  // start from the head
    printf("%d ", node_p->data); // print the first value.
    while(node_p->next != NULL){ // while you can jump
        node_p = node_p->next; // jump to next node
        printf("%d ", node_p->data); // print current node data
    }
    printf("\n");
}


// ===Remove===
void removeEnd(struct HeadTail* headTail_p) { 
    // Check if head/tail are null
    if (headTail_p->head == NULL && headTail_p->tail == NULL) { 
        return; // don't do anything because it's already an empty list
    }

    // Check if there is only 1 node
    if (headTail_p->tail->back == NULL) {
        free(headTail_p->tail); // free the tail
        headTail_p->tail = NULL; headTail_p->head = NULL; // make the tail and head equal to NULL
        return;
    }

    // if linked list size > 1

    struct Node* prevNode = headTail_p->tail->back;

    free(headTail_p->tail); // get rid of the old tail

    prevNode->next = NULL; // cut link to old tail
    headTail_p->tail = prevNode; // the current tail is now the previos node
}

void removeStart(struct HeadTail* headTail_p) { 
    // Check if empty list
    if (headTail_p->head == NULL && headTail_p->tail == NULL) { 
        return; // don't do anything because it's already an empty list
    }

    // Check if 1 Node
    if (headTail_p->head->next == NULL) {  // this is if there is only 1 node, so we should make the head NULL as well
        free(headTail_p->head); // free the head
        headTail_p->tail = NULL; headTail_p->head = NULL; // make the tail and head equal to NULL

        return;
    }

    // if linked list size > 1

    struct Node* nextNode = headTail_p->head->next;
    
    free(headTail_p->head); // we free the old head.
    nextNode->back = NULL; // Cut link to old head  
    headTail_p->head = nextNode; // nextNode is now new head
}

void freeAll(struct HeadTail* headTail_p) {
    // Check Null
    if (headTail_p->head == NULL && headTail_p->tail == NULL) { 
        return; // don't do anything because it's already an empty list
    }

    // Cycle through and clear all of the memory.
    struct Node*i = headTail_p->head; // i points to the same location
    struct Node*j = i->next; // used to store next pointer before freeing the memory
    while(i->next!=NULL){
        free(i); // free the space
        i = j; // jump
        j = i->next; // save before deletion
    }
    free(i); // free last value.
    printf("[Memory freed]\n");
}

#endif

