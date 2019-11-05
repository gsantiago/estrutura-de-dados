#include <stdlib.h>
#include <stdio.h>
#include "linked-list.h"

Node* ll_create_node(int data)
{
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Node* ll_append(Node* head, Node* node)
{
  Node* tail = ll_tail(head);
  tail->next = node;
  return node;
}

Node* ll_tail(Node* head)
{
  while (head->next != NULL) {
    head = head->next;
  }

  return head;
}

Node* ll_insert(Node** head, Node* node)
{
  node->next = *head;
  *head = node;
  return node;
}

Node* ll_find(Node* head, int needle)
{
  while (head != NULL) {
    if (head->data == needle) {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

Node* ll_insert_after(Node* target, Node* node)
{
  Node* aux = target->next;
  target->next = node;
  node->next = aux;

  return node;
}

Node* ll_insert_before(Node** head, Node* target, Node* node)
{
  if (*head == target) {
    return ll_insert(head, node);
  }

  Node* aux = *head;

  while (aux->next != target) {
    aux = aux->next;
  }

  aux->next = node;
  node->next = target;

  return node;
}

void ll_remove(Node** head, Node* node)
{
  Node* aux = *head;

  if (*head == node) {
    *head = node->next;
    free(aux);
  } else {
    while (aux->next != node) {
      aux = aux->next;
    }

    aux->next = node->next;
    free(node);
  }
}

void ll_filter(Node** head, filter_callback callback)
{
  Node* aux = *head;
  Node* tmp;

  while (aux != NULL) {
    if (!callback(aux->data)) {
      tmp = aux->next;
      ll_remove(head, aux);
      aux = tmp;
    }
    aux = aux->next;
  }
}

void ll_print(Node *node)
{
  while (node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}
