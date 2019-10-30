#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_chars.h"

char* infix_to_postfix(char *infix);

int main () {
  printf("\n\n");

  // printf("%s\n", infix_to_postfix("(A+B)"));
  printf("%s\n", infix_to_postfix("(A+B+C*D-E*F*G)"));

  printf("\n\n");
  return 0;
}

char* infix_to_postfix (char *infix) {
  Stack stack;
  stack_init(&stack);
  char *postfix = malloc(0);
  int postfix_index = 0;

  for (int i = 0; infix[i] != '\0'; i++) {
    if (infix[i] == '(') {
      continue;
    } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
      stack_push(&stack, infix[i]);
    } else if (infix[i] == ')') {
      postfix = realloc(postfix, sizeof(postfix_index + 1) * sizeof(char));
      postfix[postfix_index++] = stack_pop(&stack);
    } else {
      postfix = realloc(postfix, sizeof(postfix_index + 1) * sizeof(char));
      postfix[postfix_index++] = infix[i];
    }
  }

  return postfix;
}
