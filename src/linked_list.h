#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node { 
    int data;
    struct node* next;
} node; 

void Push(struct node** headRef, int newData);

int Length( struct node* head); 

struct node* BuildOneTwoThree();

#endif

