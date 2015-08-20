#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <queue>

typedef struct Node {
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  int key;
} Node;

typedef struct Tree {
  struct Node *root;
} Tree;

Node *createNode( int key, Node *parent ) {
  Node *node = (Node *) malloc( sizeof( Node ) );
  
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->parent = parent;

  return node;
}

Tree *createTree() {
  Tree *tree = (Tree *) malloc( sizeof( Tree ) );
  tree->root = NULL;

  return tree;
}

void printInOrder( Node *node ) {
  if ( node->left != NULL ) {
    printInOrder( node->left );
  }

  printf( "%d\n", node->key );

  if ( node->right != NULL ) {
    printInOrder( node->right );
  }
}

void printByRow( Node *node ) {
  std::queue<Node *> currentRow, nextRow;

  currentRow.push( node );

  while ( !currentRow.empty() ) {
    Node *currentNode = currentRow.front();
    currentRow.pop();
    
    if ( currentNode->left != NULL ) {
      nextRow.push( currentNode->left );
    }

    if ( currentNode->right != NULL ) {
      nextRow.push( currentNode->right );
    }

    std::cout << currentNode->key << ' ';

    if ( currentRow.empty() ) {
      std::cout << '\n';
      swap( currentRow, nextRow );
    }
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
    return max( node->right );
  }

  return node;
}

void insert( Tree *tree, int key ) {
  Node *insertNode = tree->root;
  Node *insertNodeParent = NULL;

  while ( insertNode != NULL ) {
    insertNodeParent = insertNode;
    if ( key > insertNode->key ) {
      insertNode = insertNode->right;
    } else {
      insertNode = insertNode->left;
    }
  }

  // tree is empty
  if ( insertNodeParent == NULL ) {
    tree->root = createNode( key, NULL );
  } else if ( key > insertNodeParent->key ) {
    insertNode = createNode( key, insertNodeParent );
    insertNodeParent->right = insertNode;
  } else {
    insertNode = createNode( key, insertNodeParent );
    insertNodeParent->left = insertNode;
  }
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
  Tree *tree = createTree();

  insert( tree, 5 );
  insert( tree, 4 );
  insert( tree, 6 );
  insert( tree, 3 );
  insert( tree, 7 );
  insert( tree, 2 );

  printInOrder( tree->root );
  printf( "\n" );
  printByRow( tree->root );
  printf( "\n" );

  Node *maxNode = max( tree->root );
  Node *minNode = min( tree->root );

  printf( "Max: %d\n", maxNode->key );
  printf( "Min: %d\n", minNode->key );

  return 0;
}
