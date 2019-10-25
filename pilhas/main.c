#include <stdio.h>
#include "stack.h"

int main () {
  Stack stack;

  // Inicialização da pilha
  stack_init(&stack);

  // A pilha deve estar vazia
  printf("A pilha está vazia? %d\n", stack_is_empty(&stack));

  // Inserções
  stack_push(&stack, 1);
  stack_push(&stack, 2);
  stack_push(&stack, 3);

  // A pilha deve estar com tamanho 3
  printf("Tamanho da pilha: %d\n", stack_size(&stack));

  // Elemento do topo da pilha
  printf("Elemento do topo: %d\n", stack_stackpop(&stack));

  // Remova os dois últimos elementos da pilha
  printf("Elemento %d removido\n", stack_pop(&stack));
  printf("Elemento %d removido\n", stack_pop(&stack));

  // Tamanho da pilha agora deve ser 1
  printf("Tamanho da pilha: %d\n", stack_size(&stack));

  // Remova mais um elemento para deixar a pilha vazia
  stack_pop(&stack);

  printf("Tamanho da pilha: %d\n", stack_size(&stack));

  return 0;
}
