#include <criterion/criterion.h>

#include "../src/linked_list.h"

Test(linkedlisttests, create) {
  node *current_list = BuildOneTwoThree();

  cr_expect(current_list != NULL, "List should not be null");
}
