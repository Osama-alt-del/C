// ToDO: you need to allocate nodes dynamically (using malloc)
// ask chat for more improvments (claude is slow)
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next; // next pointer
    struct node* back; // back pointer
    int data; // this is the  data that the element contains
};

struct node createNode(int); 

void appendNode(struct node**, struct node*); // call by reference
void prependNode(struct node**, struct node*); // call by reference
void removeEnd(struct node**);
void removeStart(struct node**);
void printList(struct node*); // just need head

int main() { 
    struct node node1 = createNode(6); // create the second node
    struct node node2 = createNode(7); // create the third node
    struct node node3 = createNode(8); // create the third node

    struct node* head_p = &node1; // points to first
    struct node* tail_p = &node1; // point to last

    // appendNode(&tail_p, &node1);  // we don't need this, because the head and tail already include this.
    appendNode(&tail_p, &node2);
    appendNode(&tail_p, &node3);

    struct node node4 = createNode(5); // prepend node4
    prependNode(&head_p, &node4);
    struct node node5 = createNode(4); // prepend node5
    prependNode(&head_p, &node5);


    printList(head_p);

    removeEnd(&tail_p);
    
    printList(head_p); 

    removeEnd(&tail_p);

    printList(head_p); 

    removeStart(&head_p); // works like a charm

    printList(head_p); 
    return 0;
}


// Create node:
struct node createNode(int value) { 
    struct node newNode;
    newNode.data = value;
    newNode.next = NULL;
    newNode.back = NULL; 
    return newNode;
}

// Insert at end O(1) with tail pointer
void appendNode(struct node** tail_p_p, struct node* newNode_p) { 
    (*tail_p_p)->next = newNode_p; // you now point to the newNode.  
    newNode_p->back = (*tail_p_p); // back of new is old tail
    *tail_p_p = newNode_p; // the newNode is now the tail.
}

// Add to the start O(1)
void prependNode(struct node** head_p_p, struct node* newNode_p) { 
    newNode_p->next = *head_p_p; // newNode points to head
    (*head_p_p)->back = newNode_p; // old head points back to new
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

// ===Remove===
// we have "back" so this should be easier:
void removeEnd(struct node** tail_p_p) { 
    // you should also make head NULL here, and tail NULL is the other one
    if ((*tail_p_p)-> back == NULL) { 
        *tail_p_p = NULL; // If there's only 1 node, then make the header NULL
        return;
    }

    struct node* prevNode = (*tail_p_p)->back;

    (*tail_p_p)->back = NULL; // remove tail back
    (*tail_p_p)->next = NULL; // remove tail next

    prevNode->next = NULL; // cut link to old tail
    *tail_p_p = prevNode; // the current tail is now the previos node
}

void removeStart(struct node** head_p_p) { 
    if ((*head_p_p)-> next == NULL) { 
        *head_p_p = NULL; // If there's only 1 node, then make the header NULL
        return;
    }

    struct node* nextNode = (*head_p_p)->next;
    
    (*head_p_p)->back = NULL; // remove head back
    (*head_p_p)->next = NULL; // remove head next

    nextNode->back = NULL; // Cut link to old head  
    (*head_p_p) = nextNode; // nextNode is now new head
}
