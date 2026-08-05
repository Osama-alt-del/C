// This is a program where I will make a singly linked list. (the linked list will only take the data and then it will link the elements together. It needs to know the  pointer

// hint 1: arrow operator: foo->bar = (*foo).bar (it gets the member called bar from the struct that foo points to (very useful)

// hint 2: you need to "call by reference" not call by value.
// ifyou just pass head, then it will make a "copy" of head in that function scope, it won't edit the real head

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next; // this is the pointer pointing to the next node
    int data; // this is the  data that the element contains
};

struct node createNode(int);
void appendNode(struct node, struct node*); // to add, we need the head and an element. 
void printList(struct node); // we just need the head

int main() { 
    struct node head = createNode(5); // create the first node (head)
    printf("head: %p\n", &head); // the real memory address of head.
    
    struct node node1 = createNode(6); // create the second node

    appendNode(head, &node1);  // this isn't working and I'm gonna cry

    // printf("%p\n", head.next);   

    printList(head); // should print out 5, 6

    
    return 0;
}

// I will try and make it on my own, without searching up on google either.

// Create node:
struct node createNode(int value) { 
    struct node newNode;
    newNode.data = value;
    newNode.next = NULL; // for now you don't have to point to anything
    return newNode;
}

// append:
void appendNode(struct node head, struct node* newNode) { 
    struct node* i = &head; // we start at head (maybe the problem is that I need to pass heads pointer as well)
    printf("i: %p\n", i); // this should be pointing to head
    while (i->next != NULL) { 
        // printf("running\n");
        i = i->next; // become the next node that you are pointing to.
    }
    // printf("%d\n", i.data);
    i->next = newNode; // you now point to the new node. 
    printf("this is the pointer: %p\n",i->next);
}

// print everything:
void printList(struct node head) {
    struct node* i = &head; // has to be a pointer to change the value
    printf("%d ", i->data); // print the first value.
    while(i->next != NULL){  // while will not print the last value, so I need a 
        printf("%d ", i->data); // print the data in I
        i = i->next; // you are now what i is pointing to (become the next node).
    }
    printf("\n");
}

// Remove

