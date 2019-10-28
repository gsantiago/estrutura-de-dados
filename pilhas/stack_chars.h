#include <stdbool.h>

typedef struct {
	char *items;
	int top;
} Stack;

void stack_init(Stack *stack);
bool stack_is_empty(Stack *stack);
char stack_pop(Stack *stack);
void stack_push(Stack *stack, char item);
int stack_size(Stack *stack);
char stack_stackpop(Stack *stack);
void stack_print(Stack *stack);
