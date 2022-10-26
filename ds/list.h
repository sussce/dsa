#ifndef LIST_H
#define LIST_H
#include "container_of.h"

typedef struct list {
  struct list *prev, *next;
} list;

#define list_entry(ptr, type, member) \
  container_of(ptr, type, member)

#define LIST_INIT(list) {&(list), &(list)}

#define list_is_empty(head) (head->next == head)
#define list_is_head(head, entry) (head == entry)
#define list_is_first(head, entry) (head->next == entry)
#define list_is_last(head, entry) (head == entry->next)

#define for_list(type, head, node) \
  for (type *node = head; node; node = node->next)
#define list_for_each(head, pos) \
  for(pos = head->next; !(list_is_head(head, pos)); pos = pos->next)
#define list_for_each_safe(head, n, pos) \
  for(pos = head->next, n = pos -> next; pos != (head); \
      pos = n, n = pos -> next)

void list_init(list *head);
void list_add(list *head, list *new);
void list_add_tail(list *head, list *new);
void __list_add(list *new, list *prev, list *next);
void list_del(list* del);
void __list_del(list *prev, list *next);
void list_move(list *head, list *move);
void list_move_tail(list *head, list *move);
void list_replace(list *old, list *new);
void list_swap(list *a, list *b);
void list_rotate(list *head);
void list_reverse(list *head);

list *head = NULL, *current = NULL;

void list_init(list *head) {
  head->prev = head;
  head->next = head;
}

void __list_add(list *new, list *prev, list *next) {
  prev->next = new;
  next->prev = new;
  new->prev = prev;
  new->next = next;
}

void list_add(list *head, list *new) {
  __list_add(new, head, head->next);
}

void list_add_tail(list *head, list *new) {
  __list_add(new, head->prev, head);
}

void list_del(list* del) {
  __list_del(del->prev, del->next);
  list_init(del);
}

void __list_del(list *prev, list *next) {
  prev->next = next;
  next->prev = prev;
}

void list_move(list *head, list *move) {
  list_del(move);
  list_add(head, move);
}

void list_move_tail(list *head, list *move) {
  list_del(move);
  list_add_tail(head, move);
}

void list_replace(list *old, list *new) {
  __list_add(new, old->prev, old->next);
  list_init(old);
}

void list_swap(list *a, list *b) {
  list *pos = b->prev;
  list_del(b);
  list_replace(a, b);
  if (pos == a) pos = b;
  list_add(pos, a);
}

void list_rotate(list *head) {/**/}

void list_reverse(list *head) {/**/}

#endif

