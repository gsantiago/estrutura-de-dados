#include <stdbool.h>

typedef struct {
	int *items;
	int top;
} Stack;

void stack_init(Stack *stack);
bool stack_is_empty(Stack *stack);
int stack_pop(Stack *stack);
void stack_push(Stack *stack, int item);
int stack_size(Stack *stack);
int stack_stackpop(Stack *stack);
void stack_print(Stack *stack);
