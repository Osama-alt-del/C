// This is a program where I will make a singly linked list. (the linked list will only take the data and then it will link the elements together. It needs to know the  pointer

// hint 1: arrow operator: foo->bar = (*foo).bar (it gets the member called bar from the struct that foo points to (very useful)

// hint 2: you need to "call by reference" not call by value.
// if you just pass head, then it will make a "copy" of head in that function scope, it won't edit the real head

// if you every want to actually change a value outside of a function, then you always have to pass it's pointer. If that value is a pointer, then you have to pass the pointer's pointer (tail)

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next; // next pointer
    int data; // this is the  data that the element contains
};

struct node createNode(int); 
void appendNode(struct node**, struct node*); // call by reference
void prependNode(struct node**, struct node*); // call by reference
void printList(struct node*); // just need head

int main() { 
    struct node node1 = createNode(6); // create the second node
    struct node node2 = createNode(7); // create the third node
    struct node node3 = createNode(8); // create the third node

    struct node* head = &node1; // points to first
    struct node* tail_p = &node1; // point to last

    appendNode(&tail_p, &node1); 
    appendNode(&tail_p, &node2);
    appendNode(&tail_p, &node3);

    struct node node4 = createNode(5); // prepend node4
    prependNode(&head, &node4);
    struct node node5 = createNode(4); // prepend node5
    prependNode(&head, &node5);


    printList(head);
    
    return 0;
}


// Create node:
struct node createNode(int value) { 
    struct node newNode;
    newNode.data = value;
    newNode.next = NULL; // for now you don't have to point to anything
    return newNode;
}

// Insert at end O(1) with tail pointer
void appendNode(struct node** tail_p_p, struct node* newNode_p) { 
    //O(1) solution (taking tail as a paramter)
    (*tail_p_p)->next = newNode_p; // you now point to the newNode.  
    *tail_p_p = newNode_p; // the newNode is now the tail.

    /* O(n) solution: (taking head as a paramter)
    struct node* i = head;
    while (i->next != NULL) { 
        // printf("running\n");
        i = i->next; // become the next node that you are pointing to.
    }
    i->next = newNode; // you now point to the new node. 
    */
}

// Add to the start O(1)
void prependNode(struct node** head_p_p, struct node* newNode_p) { 
    newNode_p->next = *head_p_p; // newNode points to head
    *head_p_p = newNode_p; // newNode is now the head
}

// Print (O(N))
void printList(struct node* head_p) {
    struct node* node_p = head_p; 
    printf("%d ", node_p->data); // print the first value.
    while(node_p->next != NULL){ // while you can jump
        node_p = node_p->next; // jump to next node
        printf("%d ", node_p->data); // print current node data
    }
    printf("\n");
}

// Remove

