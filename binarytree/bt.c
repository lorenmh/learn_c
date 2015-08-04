#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  int key;
} Node;

typedef struct Tree {
  struct Node *root;
} Tree;

Node *createNode() {
  return (Node *) malloc( sizeof( Node ) );
}

Tree *createTree() {
  Tree *tree = (Tree *) malloc( sizeof( Tree ) );
  Node *root = createNode();

  root->left = NULL;
  root->right = NULL;
  root->parent = NULL;
  root->key = 0;

  tree->root = root;

  return tree;
}

int main( int argc, char *argv[] ) {
  
  return 0;
}
