#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  struct Node *next;
  int value;
} Node;

typedef struct LinkedList {
  struct Node *head;
} LinkedList;

Node *createNode() {
  return (Node *) malloc( sizeof( Node ) );
}

LinkedList *createList() {
  LinkedList *list = (LinkedList *) malloc( sizeof( LinkedList ) );
  Node *head = createNode();

  head->prev = NULL;
  head->next = NULL;
  head->value = 0;

  list->head = head;

  return list;
}

void appendNode( Node *node, int value ) {
  Node *newNode = createNode();

  node->next = newNode;

  newNode->prev = node;
  newNode->next = NULL;
  newNode->value = value;
}

void removeNode( Node *node ) {
  node->prev->next = node->next;
  node->next->prev = node->prev;

  free( node );
}

void insertNode( Node *node, int value ) {
  Node *newNode = createNode();
  
  Node *prev = node->prev;

  node->prev = newNode;
  prev->next = newNode;

  newNode->prev = prev;
  newNode->next = node;
  newNode->value = value;
}

Node *lastNode( LinkedList *list ) {
  Node *node = list->head;

  while ( node->next != NULL ) {
    node = node->next;
  }

  return node;
}

Node *nodeAtIndex( LinkedList *list, int index ) {
  Node *node = list->head;
  int currentPosition = 0;

  while ( (node = node->next) != NULL ) {
    if ( (currentPosition++) == index ) {
      return node;
    }
  }

  return NULL;
}

void append( LinkedList *list, int value ) {
  appendNode( lastNode( list ), value );
}

void printList( LinkedList *list ) {
  Node *node = list->head;

  printf("[");
  while ( (node = node->next) != NULL ) {
    printf( "%d", node->value );
    if (node->next != NULL) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main( int argc, char *argv[] ) {
  LinkedList *list = createList();

  append( list, 3 );
  append( list, 5 );
  append( list, 7 );
  append( list, 11 );
  append( list, 13 );
  append( list, 17 );

  printList( list );

  removeNode( nodeAtIndex( list, 2 ) );

  printList( list );

  insertNode( nodeAtIndex( list, 2 ), 123 );

  printList( list );

  return 0;
}
