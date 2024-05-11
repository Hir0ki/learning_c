#include <stdio.h>
#include <stdlib.h>

void BasicsCaller(); 
struct node { 
    int data;
    struct node* next;
};


int main(int argc, char *argv[]) {
    printf("hello world\n");
    BasicsCaller();



}

int Length( struct node* head) {
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++; 
        current = current->next;
    }
    return 0;
};

struct node* BuildOneTwoThree(){
    struct node* head = malloc(sizeof(struct node)); 
    struct node* second = malloc(sizeof(struct node));   
    struct node* third = malloc(sizeof(struct node)); 

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = NULL;


    return head;
};

void Push(struct node** headRef, int newData){

};


void BasicsCaller() {
    struct node* head;
    int len;
     head = BuildOneTwoThree(); // Start with {1, 2, 3}
    Push(&head, 13); // Push 13 on the front, yielding {13, 1, 2, 3}
     // (The '&' is because head is passed
     // as a reference pointer.)
    Push(&(head->next), 42); // Push 42 into the second position
    // yielding {13, 42, 1, 2, 3}
    // Demonstrates a use of '&' on
    // the .next field of a node.
    // (See technique #2 below.)
    len = Length(head); // Computes that the length is 5.
}
