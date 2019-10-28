#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_chars.h"

void reverse_words(Stack *stack, char *string);

int main () {
  Stack stack;
  stack_init(&stack);

  reverse_words(&stack, "ESTE EXERCICIO E MUITO FACIL");

  printf("Frase reversa: ");

  while (!stack_is_empty(&stack)) {
    printf("%c", stack_pop(&stack));
  }

  printf("\n\n");

  return 0;
}

void reverse_words (Stack *stack, char *string) {
  char word[100];
  int word_index = 0;

  for (int i = strlen(string) - 1; i >= 0; i--) {
    if (string[i] != ' ') {
      word[word_index] = string[i];
      word[word_index + 1] = '\0';
    }

    if (string[i] == ' ' || i == 0) {
      for (int j = strlen(word) - 1; j >= 0; j--) {
        stack_push(stack, word[j]);
      }

      if (string[i] == ' ') {
        stack_push(stack, ' ');
      }

      word_index = 0;
    } else {
      word_index++;
    }
  }
}
