#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_chars.h"

bool is_palindrome(char *string);

int main () {
  printf("\n\n");

  assert(is_palindrome("ana"));
  assert(is_palindrome("ame o poema"));
  assert(is_palindrome("luz azul"));

  printf("\n\n");
  return 0;
}

bool is_palindrome (char *string) {
  Stack stack;
  stack_init(&stack);

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] != ' ') {
      stack_push(&stack, string[i]);
    }
  }

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] != ' ' && string[i] != stack_pop(&stack)) {
      return false;
    }
  }

  return true;
}
