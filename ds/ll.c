#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

void display(LinkedList *ll) {
  if (ll->head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  Node *temp = ll->head;
  while (temp != NULL) {
    printf("value x: %d, ", temp->data.x);
    printf("value y: %d\n", temp->data.y);
    temp = temp->next;
  }
}

void addFirst(LinkedList *ll, Point value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data.x = value.x;
  newNode->data.y = value.y;
  newNode->next = ll->head;

  ll->head = newNode;
}

void addLast(LinkedList *ll, Point value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;

  Node *temp = ll->head;
  if (temp == NULL) {
    ll->head = newNode;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void removeFirst(LinkedList *ll) {
  if (ll->head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  Node *temp = ll->head;
  ll->head = ll->head->next;
  free(temp);
}

void removeLast(LinkedList *ll) {
  if (ll->head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  if (ll->head->next == NULL) {
    ll->head = NULL;
    free(ll->head);

    return;
  }

  Node *temp = ll->head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  temp->next = NULL;
  free(temp->next);
}

int size(LinkedList *ll) {
  if (ll->head == NULL) {
    printf("Linked list is empty\n");
    return -1;
  }

  int total = 0;
  Node *temp = ll->head;
  while (temp != NULL) {
    temp = temp->next;
    total++;
  }

  return total;
}

void set(LinkedList *ll, int index, Point value) {
  if (ll->head == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  Node *temp = ll->head;
  for (size_t i = 0; i < index; i++) {
    if (temp == NULL) {
      printf("Set error (Index is out of range)\n");
      return;
    } else {
      temp = temp->next;
    }
  }

  if (temp != NULL) {
    temp->data = value;
  } else {
    printf("Set error (Index is out of range)\n");
  }
}