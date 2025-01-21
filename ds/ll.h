#ifndef LL_H
#define LL_H

typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Node {
  Point data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
} LinkedList;

void display(LinkedList *ll);
void addFirst(LinkedList *LinkedList, Point value);
void addLast(LinkedList *ll, Point value);
void removeFirst(LinkedList *ll);
void removeLast(LinkedList *ll);
int size(LinkedList *ll);
void set(LinkedList *ll, int index, Point value);

#endif