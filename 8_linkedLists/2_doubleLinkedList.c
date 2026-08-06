// ToDO: you need to allocate nodes dynamically (using malloc)
//      use a struct for head and tail so you can check them safely if they are null
//      change name of headTail in functions to headTail_p (because it's a pointer not a node)

//      Change struct name node to capital (convention)

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next; // next pointer
    struct node* back; // back pointer
    int data; // this is the  data that the element contains
};

struct HeadTail { 
    struct node* head; // this way, when they are NULL at the start, we can still access "headTail" and therefore changethem 
    struct node* tail; // we won't get segfault by first trying to access a NULL memory address
};

// for dynamic memory this will be a pointer to the memory in the heap
struct node* createNode(int);  // maybe this should be dynamic? and it should return the memory address of the node

void appendNode(struct HeadTail*, struct node*); // call by reference
void prependNode(struct HeadTail*, struct node*); // call by reference
void removeEnd(struct HeadTail*);
void removeStart(struct HeadTail*);
void printList(struct HeadTail*); // just need head
void freeAll(struct HeadTail*);

int main() { 

    struct HeadTail headTail = {NULL, NULL}; // pretty sure we can do this to say both are NULL

    // yay it works! I need to do a lot more tests though
    appendNode(&headTail, createNode(3));
    appendNode(&headTail, createNode(5));

    printList(&headTail);

    freeAll(&headTail);
    return 0;
}



// Create node: (doesn't make sense to create a node, it is not appended.
struct node* createNode(int value) { 
    /*
    struct node newNode;
    newNode.data = value;
    newNode.next = NULL;
    newNode.back = NULL; 
    return newNode;
    */
    // dynamically allocate memory for the node (using malloc) (which returns a pointer to the allocated memory 
    // this only frees memory of a certain size and returns the pointer, how do I define the node?
    struct node* i = (struct node*) malloc(sizeof(struct node));
    if (i == NULL){
         printf("[Error] createNode(): メモリーの確保に失敗しました\n");
        struct node* j;
        return  j; // return the memory of a null node 
    }
    
    i->next = NULL;
    i->back = NULL;
    i->data = value;
    return i; // we dynamically allocate the memory in the heap and then we return that pointer.
}

// Insert at end O(1) with tail pointer
void appendNode(struct HeadTail* headTail_p, struct node* newNode_p) { 
    // checking if tail is NULL
    if (headTail_p->tail == NULL) { 
        // printf("AppendNode: [EMPTY LIST] Tail is null\n");
        headTail_p->tail = newNode_p; // the new node is now the tail of the linked list
        headTail_p->head = newNode_p; // since it's empty the head also points to thew newNode
        return;
    }
    headTail_p->tail->next = newNode_p; // you now point to the newNode
    newNode_p->back = headTail_p->tail; // back of new is old tail (add to end)
    headTail_p->tail = newNode_p; // newNode is now the tail

    /*
    (*tail_p_p)->next = newNode_p; // you now point to the newNode.  
    newNode_p->back = (*tail_p_p); // back of new is old tail
    *tail_p_p = newNode_p; // the newNode is now the tail.
    */
}

// Add to the start O(1)
void prependNode(struct HeadTail* headTail_p, struct node* newNode_p) { 
    // checking if head is NULL
    if (headTail_p->head == NULL) { 
        // printf("Prepend Node: [EMPTY LIST] The head is null\n");
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

    struct node* node_p = headTail_p->head;  // start from the head
    printf("%d ", node_p->data); // print the first value.
    while(node_p->next != NULL){ // while you can jump
        node_p = node_p->next; // jump to next node
        printf("%d ", node_p->data); // print current node data
    }
    printf("\n");
}

// ===Remove===
// we have "back" so this should be easier:

// we need to use "free" because we have dynamic memory.
void removeEnd(struct HeadTail* headTail_p) { 
    // Check if head/tail are null
    if (headTail_p->head == NULL && headTail_p->tail == NULL) { 
        return; // don't do anything because it's already an empty list
    }

    // Check if there is only 1 node
    if (headTail_p->tail->back == NULL) {  // this is if there is only 1 node, so we should make the head NULL as well
        // free the tail
        free(headTail_p->tail);

        // make the tail and head equal to NULL
        headTail_p->tail = NULL; headTail_p->head = NULL;
        return;
    }

    // if linked list size > 1

    struct node* prevNode = headTail_p->tail->back;

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
        // free the head
        free(headTail_p->head);

        // make the tail and head equal to NULL
        headTail_p->tail = NULL; headTail_p->head = NULL;
        return;
    }

    // if linked list size > 1

    struct node* nextNode = headTail_p->head->next;
    
    free(headTail_p->head); // we free the old head.

    nextNode->back = NULL; // Cut link to old head  
    headTail_p->head = nextNode; // nextNode is now new head
}

// we want to access and change the "node" value which head points to, not "head" so we will use a single pointer
// this is useful at end of main()
void freeAll(struct HeadTail* headTail_p) {
    
    // free all memory here
    struct node*i = headTail_p->head; // i points to the same location
    struct node*j = i->next; // used to store next pointer before freeing the memory
    while(i->next!=NULL){
        free(i); // free the space
        i = j; // jump
        j = i->next; // save before deletion
    }
    free(i); // free last value.
    printf("[Memory freed]\n");
}
