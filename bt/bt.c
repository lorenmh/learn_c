#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  int key;
} Node;

typedef struct Tree {
  struct Node *root;
} Tree;

Node *createNode( int key, Node *left, Node *right, Node *parent ) {
  Node *node = (Node *) malloc( sizeof( Node ) );
  
  node->key = key;
  node->left = left;
  node->right = right;
  node->parent = parent;

  return node;
}

Tree *createTree() {
  Tree *tree = (Tree *) malloc( sizeof( Tree ) );
  tree->root = NULL;

  return tree;
}

bool isEmpty( Tree *tree ) {
  return tree->root == NULL;
}

void print( Node *node ) {
  if ( node->left != NULL ) {
    print( node->left );
  }

  printf( "%d", node->key );

  if ( node->right != NULL ) {
    print( node->right );
  }
}

Node *search( Node *node, int key ) {
  if ( node == NULL || key == node->key ) {
    return node;
  }

  if ( key > node->key ) {
    return search( node->right, key );
  }

  return search( node->left, key );
}

Node *min( Node *node ) {
  if ( node->left != NULL ) {
    return min( node->left );
  }

  return node;
}

Node *max( Node *node ) {
  if ( node->right != NULL ) {
    return min( node->right );
  }

  return node;
}

Node *successor( Node *node ) {
  if ( node->right != NULL ) {
    return min( node->right );
  }

  Node *parent = node->parent;

  while( parent != NULL && node == parent->right ) {
    node = parent;
    parent = node->parent;
  }

  return parent;
}

int main( int argc, char *argv[] ) {
  
  return 0;
}
