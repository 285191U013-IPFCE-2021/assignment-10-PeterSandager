#include "../include/linked_list.h"
#include <stdio.h>
/*
 * Linked list
 */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */

/* functions to create lists */
node *make_node(int v, node *q)
{
  node *p = malloc(sizeof(node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p)
{
  node *q = p;
  while (q != &SENTINEL_node)
  {
    node *t = q->next;
    free(q);
    q = t;
  }
}

/* print list to console */
void print_list(node *p)
{
  if (p == NULL)
    return;

  else
    printf("%d, ", p->value);
  print_list(p->next); // Recursive step
}

int sum_squares(node *p)
{
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  int sum;

  if (p == &SENTINEL_node)
    return 0;

  else if (p->next == &SENTINEL_node)
    return square(p->value);

  else
    return square(p->value) + sum_squares(p->next);

  return sum;
}

node *map(node *p, int (*f)(int))
{
  // Add your code for excercise 3
  if (p == &SENTINEL_node)
    return &SENTINEL_node;

  return (make_node((*f)(p->value), map(p->next, f))); // recursive step

  return NULL;
}

int square(int x)
{
  return x * x;
}
