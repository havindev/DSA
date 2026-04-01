#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
  int value;
  struct Node *next;
} Node;

typedef struct LinkedList{
  Node *head;
  Node *tail;
  int size;
}LinkedList;
Node *createNode(int value);
LinkedList *createList();
void addLast(LinkedList *list, int value);
void printList(LinkedList *list);
void reverse(LinkedList *list);
#endif
