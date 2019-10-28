# Pilhas

Pilhas são estruturas de dados simples do tipo LIFO (Last-in, first-out), ou seja,
o último item a entrar é o primeiro a sair.

![GIF](gif.gif)

## Exercícios

1) Dada uma pilha P, construir uma função que inverte a ordem dos elementos dessa pilha, utilizando apenas uma estrutura auxiliar. Definir adequadamente a estrutura auxiliar e prever a possibilidade da pilha estar vazia.
2) Construir uma função que troca de lugar o elemento que está no topo
   da pilha com o que está na base da pilha. Usar apenas uma pilha como
   auxiliar.
3) Dada uma pilha contendo números inteiros quaisquer, construir uma
   função que coloca os pares na base da pilha e os ímpares no topo da
   pilha. Usar duas pilhas como auxiliares.
4) Escreva um algoritmo que use uma pilha para inverter a ordem das letras de cada palavra de uma string ASCII, preservando a ordem das palavras. Por exemplo, para a string  ESTE EXERCICIO E MUITO FACIL  o resultado deve ser  ETSE OICICREXE E OTIUM LICAF.
5) Crie uma função que valide se expressões com parênteses e colchetes está bem formada. `( ( ) [ ( ) ] )` está bem formada, enquanto que `( ( ) ][ ( ) )` não está.

## Stack

Desenvolvi uma estrutura `Stack` que implementa o seguinte:

```c
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
```

Implementações de cada exercício:

1) `void stack_reverse(Stack *stack)` para inverter uma pilha de inteiros.
2) `void stack_swap_top_and_bottom(Stack *stack)` para trocar o topo e a base de uma pilha.
3) `void stack_sort_odd_and_even(Stack *stack)` para separar os inteiros pares de ímpares numa pilha.
4) `void reverse_words(Stack *stack, char *string)` para inverter as palavras (e não a ordem delas) de uma string.
