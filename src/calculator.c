#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void BasicsCaller();

/* int main(int argc, char *argv[]) {
  printf("hello world\n");
  BasicsCaller();
} */

void BasicsCaller() {
  struct node *head;
  int len;
  head = BuildOneTwoThree(); // Start with {1, 2, 3}
  Push(&head, 13);           // Push 13 on the front, yielding {13, 1, 2, 3}
                             // (The '&' is because head is passed
                             // as a reference pointer.)
  Push(&(head->next), 42);   // Push 42 into the second position
  // yielding {13, 42, 1, 2, 3}
  // Demonstrates a use of '&' on
  // the .next field of a node.
  // (See technique #2 below.)
  len = Length(head); // Computes that the length is 5.
  printf("Basic caller len: % \n");
}
