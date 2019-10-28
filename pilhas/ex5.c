#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_chars.h"

bool bem_formada(char string[]);

int main () {
  // Expressões válidas
  assert(bem_formada("()"));
  assert(bem_formada("[]"));
  assert(bem_formada("[()[()]]"));
  assert(bem_formada("(()[()])"));

  // Expressões inválidas
  assert(!bem_formada("())"));
  assert(!bem_formada(")("));
  assert(!bem_formada("]["));
  assert(!bem_formada("([(]))"));
  return 0;
}

bool bem_formada (char string[]) {
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
