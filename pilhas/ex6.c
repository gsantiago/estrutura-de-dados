#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include "stack.h"

int evaluate_expression(char *expression);

int main () {
  printf("\n\n");

  assert(evaluate_expression("4 2 /") == 2);
  assert(evaluate_expression("5 5 +") == 10);
  assert(evaluate_expression("2 2 + 8 4 - *") == 16);
  assert(evaluate_expression("22 22 + 2 2 - *") == 0);
  assert(evaluate_expression("4 55 + 62 23 - *") == 2301);
  assert(evaluate_expression("10 10 * 10 - 10 * 1000 * 1000 *") == 900000000);

  printf("\n\n");

  return 0;
}

int evaluate_expression(char *expression) {
  Stack stack;
  stack_init(&stack);

  char number[10];
  int number_index = 0;

  for (int i = 0; expression[i] != '\0'; i++) {
    char ch = expression[i];

    if (isdigit(ch)) {
      number[number_index] = ch;
      number_index += 1;
    } else {
      if (number_index > 0) {
        number[number_index] = '\0';
        stack_push(&stack, atoi(number));
        number[0] = '\0';
        number_index = 0;
      }

      if (ch != ' ') {
        int accum = 0;
        int second = stack_pop(&stack);
        int first = stack_pop(&stack);
        switch (ch) {
          case '+':
            accum = first + second;
            break;
          case '-':
            accum = first - second;
            break;
          case '*':
            accum = first * second;
            break;
          case '/':
            accum = first / second;
            break;
          default:
            printf("'%c' não reconhecido como operador válido\n", ch);
        }
        stack_push(&stack, accum);
      }
    }
  }

  return stack_pop(&stack);
}
