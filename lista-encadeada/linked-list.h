#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdbool.h>

struct node_struct {
  int data;
  struct node_struct *next;
};

typedef struct node_struct Node;

typedef bool (*filter_callback)(int);

Node* ll_create_node(int data);
Node* ll_append(Node* head, Node* node);
Node* ll_insert(Node** head, Node* node);
Node* ll_find(Node* head, int needle);
Node* ll_tail(Node* head);
Node* ll_insert_after(Node* target, Node* node);
Node* ll_insert_before(Node** head, Node* target, Node* node);
void ll_filter(Node** head, filter_callback callback);
void ll_remove(Node** head, Node* node);
void ll_print(Node* head);

#endif
