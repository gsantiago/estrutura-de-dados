#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_chars.h"

bool is_expression_correct(char *string);

int main () {
  // Expressões válidas
  assert(is_expression_correct("()"));
  assert(is_expression_correct("[]"));
  assert(is_expression_correct("[()[()]]"));
  assert(is_expression_correct("(()[()])"));

  // Expressões inválidas
  assert(!is_expression_correct("())"));
  assert(!is_expression_correct(")("));
  assert(!is_expression_correct("]["));
  assert(!is_expression_correct("([(]))"));
  return 0;
}

bool is_expression_correct (char *string) {
  Stack stack;
  stack_init(&stack);

  for (int i = 0; string[i] != '\0'; i++) {
    char ch;

    if (string[i] == ')') {
      if (stack_is_empty(&stack) || stack_pop(&stack) != '(') {
        return false;
      }
    } else if (string[i] == ']') {
      if (stack_is_empty(&stack) || stack_pop(&stack) != '[') {
        return false;
      }
    } else {
      stack_push(&stack, string[i]);
    }
  }

  return true;
}
