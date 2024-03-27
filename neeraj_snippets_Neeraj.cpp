#include <iostream>
#include <cstdlib>

using namespace std;

// Class for singly linked list
class LinkedList{
public:
    int data;
    class LinkedList *next;
};

// Function for traversing the singly linked list
void linkedListTraversal(class LinkedList *node){
    while(node!=NULL){
        cout <<"Elements: "<<node->data<<endl;
        node = node->next;
    }
}

// Function for insertion at front (single linked list)
class LinkedList *insertAtfront(class LinkedList *node, int num){
    LinkedList *ptr;
    ptr = (class LinkedList*)malloc(sizeof(struct LinkedList));
    ptr->data = num;
    ptr->next = node;
    return ptr;
}

// Function for insertion at end (singly linked list)
class LinkedList *insertAtEnd(class LinkedList *node, int num){
    LinkedList *p = node;
    LinkedList *ptr;
    ptr = (class LinkedList*)malloc(sizeof(struct LinkedList));
    while((p->next)!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = num;
    ptr->next = NULL;
    return node;
}

// Function for insertion at index (singly linked list)
class LinkedList *insertAtIndex(class LinkedList *node, int num, int index){
    class LinkedList *ptr;
    ptr = (class LinkedList*)malloc(sizeof(class LinkedList));
    class LinkedList *p = node;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = num;
    ptr->next = p->next;
    p->next = ptr;
    return node;
}

// Function for insertion after Node (singly linked list)
class LinkedList *insertAfterNode(class LinkedList *node, class LinkedList *PrevNode, int num){
    class LinkedList *ptr;
    ptr = (class LinkedList *)malloc(sizeof(class LinkedList));
    ptr -> data = num;
    ptr -> next = PrevNode->next;
    PrevNode->next = ptr;
    return node;
}

// Class for doubly linked list
class DoublyLinkedList{
public:
    int data;
    class DoublyLinkedList *prev;
    class DoublyLinkedList *next;
};

// Function for traversing in forward order Doubly linked list
void doublyLinkedListTraversal(class DoublyLinkedList *node){
    while(node!=NULL){
        cout <<"Elements: " << node->data <<endl;
        node = node->next;
    }
}

// Function for traversing in Reverse order Doubly Linked list
void doublyLinkedListReverseTraversal(class DoublyLinkedList *node){
    while(node!=NULL){
        cout <<"Elements: " << node->data <<endl;
        node = node->prev;
    }
}

// Function for deletion of Head (singly linked list)
class LinkedList *deletingHead(class LinkedList *node){
    LinkedList *ptr = node;
    node = node->next;
    free(ptr);
    return node;
}

// Function for deletion of Last Node (singly Linked List)
class LinkedList *deletionOfTail(class LinkedList *node){
    class LinkedList *p = node;
    class LinkedList *q = node->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next =  NULL;
    free(q);
    return node;
}

// Function for deletion in between (singly Linked list)
class LinkedList *deletionAtIndex(class LinkedList *node, int index){
    class LinkedList *p = node;
    class LinkedList *q = node->next;
    int i=0;
    while(i != (index-1)){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return node;
}

// Function for deletion By Value (singly Linked list)
class LinkedList *deletionByValue(class LinkedList *node, int value){
    class LinkedList *p = node;
    class LinkedList *q = node->next;
    if(node->data == value){
        node = node->next;
        free(p);
    }
    else{
        while(q->data != value && q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        if(q->data == value){
            p->next = q->next;
            free(q);
        }
    }
    return node;
}

// Function for Traversal in Circular LinkedList
void CircularLinkedListTraversal(class CircularLinkedList *node){
    class CircularLinkedList *p = node;
    do{
        cout<<"Elements: "<<node->data <<endl;
        node = node->next;
    } while(node!=p);
}

// Function for Insertion at head (circular linked list)
class CircularLinkedList *insertionAtHead(class CircularLinkedList *node, int value){
    class CircularLinkedList *q = node;
    class CircularLinkedList *p;
    p = (class CircularLinkedList*)malloc(sizeof(class CircularLinkedList));
    p->data = value;
    p->next = node;
    do{
        node = node->next;
    } while(node->next!=q);
    node->next = p;
    return p;
}
// for deletion by value (doubly Linked List)
class DoublyLinkedList *deletionByValue(DoublyLinkedList *node, int value) {
    if (node == NULL) {
        cout << "List is empty" << endl;
        return node;
    }
    DoublyLinkedList *p = node;
   
    while(p != NULL  && p->data != value){
        p = p->next;
    }
    if(p == NULL){
        cout<<"Value not found"<<endl;
        return node;
    }
    if (p->prev != NULL){
        p->prev->next = p->next;
    }
    else {
      node = p->next;
    }
    if (p->next != NULL){
        p->next->prev = p->prev;
    }
    free(p);
    return node;
}

// for deletion at index (doubly linked list)
class DoublyLinkedList *deletionAtIndex(DoublyLinkedList *node, int index) {
    if (index < 0) {
        cout << "Invalid index" << endl;
        return node;
    }

    if (node == NULL) {
        cout << "List is empty" << endl;
        return node;
    }

    if (index == 0) {
        DoublyLinkedList *q = node;
        node = node->next;
        if (node != NULL) {
            node->prev = NULL;
        }
        delete q;
        return node;
    }

    DoublyLinkedList *p = node;
    int i = 0;
    while (p != NULL && i < (index-1)) {
        p = p->next;
        i++;
    }

    if (p == NULL || p->next == NULL) {
        cout << "Index out of range" << endl;
        return node;
    }

    DoublyLinkedList *q = p->next;
    p->next = q->next;
    if (q->next != nullptr) {
        q->next->prev = p;
    }
    delete q;

    return node;
}
// deletion of tail (doubly Linked List)
class DoublyLinkedList *deletionOfTail(class DoublyLinkedList *node){
    DoublyLinkedList *p = node;
    while(p->next!=NULL){
        p = p->next;
    }
     p->prev->next = NULL;
     
     free(p);
     
    return node;
}
// deletion of head (doubly linked list)
class DoublyLinkedList *deletionOfHead(class DoublyLinkedList *node){
    DoublyLinkedList *q = node->next;
     q->prev = NULL;
     free(node);
   
    return q;
}
// insertion at index (doubly Linked List)
class DoublyLinkedList *insertionAtIndex(class DoublyLinkedList *node,int index,int value){
    int i=0;
    DoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));
    DoublyLinkedList *q = node;
   
    while(i != (index-1)){
        q = q->next;
        i++;
    }
    p->data = value;
    p->prev = q;
    p->next = q->next;
    if (q->next != NULL){
        q->next->prev = p;
    }
    q->next = p;
   
    return node;
}
// insertion aty Head
class DoublyLinkedList *insertionAtHead(class DoublyLinkedList *node,int value){
    DoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));
    p->data = value;
    p->next = node;
    p->prev = NULL;
    node->prev = p;
   
    return p;
}
//insertion at tail (doubly linked list)
class DoublyLinkedList *insertionAtTail(class DoublyLinkedList *node,int value){
    DoublyLinkedList *p = (class DoublyLinkedList *)malloc(sizeof(class DoublyLinkedList));
    DoublyLinkedList *q = node;
    p->data = value;
    p->next = NULL;
   
    while(q->next!=NULL){
        q = q->next;
    }
   
    q->next = p;
    p->prev = q;
   
    return node;
}
int main() {
    
    return 0;
}





