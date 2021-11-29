#include "../include/btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tree_node *createnode(int x)
{

  // Create new node
  struct tree_node *node = (struct tree_node *)malloc(sizeof(struct tree_node));
  node->item = x;

  node->left = NULL;
  node->right = NULL;

  return node;
}

struct tree_node *Insert(int x, struct tree_node *t)
{
  // Checking if t==null. If the list is empty
  if (t == NULL)
    return createnode(x);
  /*
     * if given x is greater than t->item,
     * we should find the correct place in the right subtree and insert the new node
     */
  if (t->item < x)
    t->right = Insert(x, t->right);
  /*
     * if given x is smallar than t->item,
     * we should find the correct place in the left subtree and insert the new node
     */
  else
    t->left = Insert(x, t->left);
  return t;

  return NULL;
}
struct tree_node *minValue(struct tree_node *t) // Creating a new struct called current.
{
  struct tree_node *current = t;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct tree_node *Remove(int x, struct tree_node *t)
{
  // base case
  if (t == NULL)
    return t;

  // If the key to be deleted is smaller than the root's key, then it lies in left subtree
  if (x < t->item)
    t->left = Remove(x, t->left);

  // The same just for the right one.
  else if (x > t->item)
    t->right = Remove(x, t->right);

  // If the key is the same as the roots key then the node will be deleted.
  else
  {
    if (t->left == NULL) // For ones with only 1 or no childs.
    {
      struct tree_node *newnode = t->right;
      free(t);
      return newnode;
    }
    else if (t->right == NULL)
    {
      struct tree_node *newnode = t->left;
      free(t);
      return newnode;

      //Nodes with the two children gets the inorders
    }
    struct tree_node *newnode = minValue(t->right);
    t->item = newnode->item;                    // Copy the inorders successors contont to this node.
    t->right = Remove(newnode->item, t->right); // Delete the inorders successor.
  }
  return t;
}

int Contains(int x, struct tree_node *t)
{

  if (t == NULL)
    return 0;
  if (t->item == x)
    return 1;
  else if (x > t->item)
    return Contains(x, t->right);
  else
    return Contains(x, t->left);

  return 1;
}

struct tree_node *Initialize(struct tree_node *t)
{
  return t = NULL;
}

int Empty(struct tree_node *t)
{
  if (t == NULL)
    return 1;
  else
    return 0;
}

int Full(struct tree_node *t)
{
  if (t == NULL)
    return 1;
  if (t->left == NULL && t->right == NULL)
    return 1;
  if ((t->left) && (t->right))
    return (Full(t->left) && Full(t->right));
  return 0;
  // Test if full
  return 0;
}
