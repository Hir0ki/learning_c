#include "../src/linked_list.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(linkedlisttests, create) {
  node *current_list = BuildOneTwoThree();

  cr_expect(current_list != NULL, "List should not be null");
}

Test(linkedlisttests, push) {
  node *head_ref;

  Push(&head_ref, 5);

  cr_expect(head_ref->data == 5);
}

Test(linkedlisttests, push_multi) {
  node *head_ref;

  Push(&head_ref, 5);
  Push(&head_ref, 8);

  cr_expect(head_ref->data == 8);
  cr_expect(head_ref->next->data == 5);
}
