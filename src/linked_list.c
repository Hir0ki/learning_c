#include "linked_list.h"
#include <stdlib.h>

int Length(struct node *head) {
  struct node *current = head;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
};

void Push(struct node **headRef, int newData){

};

struct node *BuildOneTwoThree() {
  struct node *head = malloc(sizeof(struct node));
  struct node *second = malloc(sizeof(struct node));
  struct node *third = malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 2;
  third->next = NULL;

  return head;
};
