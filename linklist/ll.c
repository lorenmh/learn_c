#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  struct Node *next;
  int value;
} Node;

typedef struct LinkedList {
  struct Node *start;
} LinkedList;

Node *NodeFactory( int value ) {
  Node *node;

  node = (Node *) malloc( sizeof( Node ) );
  
  node->value = value;

  return node;
}

int main( int argc, char *argv[] ) {
  printf( "Size of Node: %lu\n", sizeof( Node ) ); 
  
  Node *node1, *node2;


  node1 = (Node *) NodeFactory( 23 );
  node2 = (Node *) NodeFactory( 123 );

  node1->prev = NULL;
  node1->next = node2;

  node2->prev = node2;
  node2->next = NULL;

  return 0;
}
