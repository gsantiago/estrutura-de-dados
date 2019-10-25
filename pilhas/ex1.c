#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_reverse(Stack *stack);

int main () {
  Stack pilha;

  stack_init(&pilha);

  stack_push(&pilha, 1);
  stack_push(&pilha, 2);
  stack_push(&pilha, 3);
  stack_push(&pilha, 4);
  stack_push(&pilha, 5);

  stack_print(&pilha);

  printf("Reverte a ordem dos elementos da pilha:\n");

  stack_reverse(&pilha);

  stack_print(&pilha);

  return 0;
}

void stack_reverse (Stack *stack) {
  int *aux;
  int i;
  int size;

  aux = malloc(stack_size(stack) * sizeof(int));
  size = stack_size(stack);

  for (i = 0; i < size; i++) {
    aux[i] = stack_pop(stack);
  }

  for (i = 0; i < size; i++) {
    stack_push(stack, aux[i]);
  }

  free(aux);
}
