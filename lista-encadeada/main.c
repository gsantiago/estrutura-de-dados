#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linked-list.h"

bool is_even(int data) {
  return data % 2 == 0;
}

int main()
{
  Node* head = ll_create_node(1);

  for (int i = 2; i <= 20; i++) {
    ll_append(head, ll_create_node(i));
  }

  ll_print(head);

  ll_filter(&head, is_even);

  ll_print(head);

//  Node* head = ll_create_node(1);
//  head->next = ll_create_node(2);
//  ll_print(head);
//
//  ll_append(head, ll_create_node(3));
//  ll_print(head);
//
//  ll_insert(&head, ll_create_node(0));
//  ll_print(head);
//
//  printf("Último elemento da lista: %d\n", ll_tail(head)->data);
//
//  ll_insert_after(
//    ll_find(head, 2),
//    ll_create_node(100)
//  );
//  ll_print(head);
//
//  ll_insert_before(&head, ll_find(head, 2), ll_create_node(-2));
//  ll_print(head);
//
//  ll_insert_before(&head, head, ll_create_node(-1));
//  ll_print(head);
//
//  ll_remove(&head, ll_find(head, 100));
//  ll_print(head);
//
//  int element;
//  Node* result;
//
//  printf("Pesquisar nó: ");
//  scanf("%d", &element);
//  result = ll_find(head, element);
//
//  if (result != NULL) {
//    printf("Nó encontrado: %d\n", result->data);
//  } else {
//    printf("Nó não encontrado!\n");
//  }

  return 0;
}
