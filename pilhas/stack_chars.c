#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack_chars.h"

void stack_init(Stack *stack) {
  stack->top = -1;
  stack->items = malloc(sizeof(char));
}

bool stack_is_empty(Stack *stack) {
  return stack->top == -1;
}

char stack_pop(Stack *stack) {
  int item;

  if (stack_is_empty(stack)) {
    printf("A pilha está vazia");
    exit(1);
  }

  item = (stack->items[stack->top--]);

  if (stack_size(stack) > 1) {
    stack->items = realloc(stack->items, sizeof(char) * (stack_size(stack) - 1));
  }

  return item;
}

void stack_push(Stack *stack, char item) {
  stack->items = realloc(stack->items, sizeof(char) * (stack_size(stack) + 1));
  stack->items[++(stack->top)] = item;
}

int stack_size(Stack *stack) {
  return stack->top + 1;
}

char stack_stackpop(Stack *stack) {
  return stack->items[stack->top];
}

void stack_print(Stack *stack) {
  printf("----------\n");

  printf("[ ");
  for (int i = stack->top; i >= 0; i--) {
    printf("%c", stack->items[i]);
    if (i > 0) {
      printf(", ");
    }
  }
  printf(" ]\n");

  printf("---------\n");
}
