#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_swap_top_and_bottom(Stack *stack);

int main () {
  Stack stack;
  stack_init(&stack);

  stack_push(&stack, 1);
  stack_push(&stack, 2);
  stack_push(&stack, 3);
  stack_push(&stack, 4);
  stack_push(&stack, 5);

  stack_print(&stack);

  stack_swap_top_and_bottom(&stack);

  printf("Após inverter topo e base:\n");

  stack_print(&stack);

  return 0;
}

void stack_swap_top_and_bottom (Stack *stack) {
  Stack aux;
  stack_init(&aux);

  int top = stack_stackpop(stack);
  int bottom;

  while (!stack_is_empty(stack)) {
    stack_push(&aux, stack_pop(stack));
  }

  bottom = stack_stackpop(&aux);

  while (!stack_is_empty(&aux)) {
    if (stack_size(stack) == 0) {
      stack_push(stack, top);
      stack_pop(&aux);
    } else if (stack_size(&aux) == 1) {
      stack_push(stack, bottom);
      stack_pop(&aux);
    } else {
      stack_push(stack, stack_pop(&aux));
    }
  }
}
