#include "../include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{

  int weight;
  unsigned char character;
  Tree *left;
  Tree *right;
};

//=======================================================================//
Tree *CreateVoidTree() { return NULL; }

//=======================================================================//
Tree *CreateLeafNode(Tree *left, Tree *right, int weight, unsigned char character)
{

  Tree *tree = malloc(sizeof(Tree));
  tree->left = left;
  tree->right = right;
  tree->weight = weight;
  tree->character = character;

  return tree;
}

//=======================================================================//
Tree *CreateInternalNode(Tree *left, Tree *right, int weight)
{

  Tree *tree = malloc(sizeof(Tree));
  tree->left = left;
  tree->right = right;
  tree->weight = weight;
  tree->character = '\0';

  return tree;
}

//=======================================================================//
int TreeHeight(Tree *tree)
{

  if (!tree)
    return -1;

  if (TreeHeight(tree->left) > TreeHeight(tree->right))
    return 1 + TreeHeight(tree->left);
  else
    return 1 + TreeHeight(tree->right);
}

//=======================================================================//
int TreeWeight(Tree *tree)
{
  if (!tree)
    return -1;
  return tree->weight;
}

//=======================================================================//
void PrintTree(Tree *tree)
{

  if (tree)
  {
    printf("-> %d / %c\n", tree->weight, tree->character);
    PrintTree(tree->left);
    PrintTree(tree->right);
  }
}

//=======================================================================//
void FillEncodeTable(char **table, Tree *tree, unsigned char *code, int treeHeight)
{

  if (!tree->left && !tree->right)
  {
    strcpy(table[tree->character], code);
    return;
  }

  char left[treeHeight], right[treeHeight];
  strcpy(left, code);
  strcpy(right, code);
  strcat(left, "0");
  strcat(right, "1");

  FillEncodeTable(table, tree->left, left, treeHeight);
  FillEncodeTable(table, tree->right, right, treeHeight);
}