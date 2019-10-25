#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_sort_odd_and_even(Stack *stack);

int main () {
  Stack stack;
  stack_init(&stack);

  int input = -1;

  while (input != 0) {
    printf("Adicionar número (entre 0 para finalizar): ");
    scanf("%d", &input);
    if (input != 0) {
      stack_push(&stack, input);
    }
  }

  stack_sort_odd_and_even(&stack);

  stack_print(&stack);

  return 0;
}

void stack_sort_odd_and_even(Stack *stack) {
  Stack even_numbers;
  Stack odd_numbers;
  stack_init(&even_numbers);
  stack_init(&odd_numbers);

  while (!stack_is_empty(stack)) {
    if (stack_stackpop(stack) % 2 == 0) {
      stack_push(&even_numbers, stack_pop(stack));
    }  else {
      stack_push(&odd_numbers, stack_pop(stack));
    }
  }

  while (!stack_is_empty(&even_numbers)) {
    stack_push(stack, stack_pop(&even_numbers));
  }

  while (!stack_is_empty(&odd_numbers)) {
    stack_push(stack, stack_pop(&odd_numbers));
  }
}
