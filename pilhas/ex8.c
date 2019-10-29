#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack_chars.h"

#define BINARY 2
#define OCTAL 8
#define HEXADECIMAL 16

void assert_string(char *a, char *b);
char* convert(int number, int base);

int main () {
  // BINARY
  assert_string(convert(0, BINARY), "0");
  assert_string(convert(1, BINARY), "1");
  assert_string(convert(4, BINARY), "100");
  assert_string(convert(29, BINARY), "11101");
  assert_string(convert(10, BINARY), "1010");
  assert_string(convert(15, BINARY), "1111");
  assert_string(convert(489516, BINARY), "1110111100000101100");

  // OCTAL
  assert_string(convert(0, OCTAL), "0");
  assert_string(convert(1, OCTAL), "1");
  assert_string(convert(61, OCTAL), "75");
  assert_string(convert(123, OCTAL), "173");
  assert_string(convert(2789, OCTAL), "5345");

  // HEXADECIMAL
  assert_string(convert(0, HEXADECIMAL), "0");
  assert_string(convert(16, HEXADECIMAL), "10");
  assert_string(convert(8000, HEXADECIMAL), "1F40");
  assert_string(convert(14891563, HEXADECIMAL), "E33A2B");

  return 0;
}

void assert_string (char *a, char *b) {
  assert(strcmp(a, b) == 0);
}

char* convert(int number, int base) {
  char digits[16] = "0123456789ABCDEF";
  Stack stack;
  stack_init(&stack);

  if (number == 0) {
    return "0";
  }

  while (number > 0) {
    stack_push(&stack, digits[number % base]);
    number = number / base;
  }

  char *result = malloc(stack_size(&stack) * sizeof(char));

  for (int i = 0; !stack_is_empty(&stack); i++) {
    result[i] = stack_pop(&stack);
  }

  return result;
}
