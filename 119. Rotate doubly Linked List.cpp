// https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1

#include <bits/stdc++.h>

using namespace std;

typedef struct node {
  int data;
  struct node *next, *prev;

  node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
  }

} Node;

Node *lastNode(Node *node) {
  if (!node or !node->next) return node;
  return lastNode(node->next);
}

Node *ithNode(Node *node, int pos) {
  while (pos-- > 1) node = node->next;
  return node;
}

Node *rotateDLL(Node *start, int p) {
  auto ith_node = ithNode(start, p);
  if (!ith_node->next) return start;

  auto last_node = lastNode(ith_node->next);
  auto newStart = ith_node->next;
  ith_node->next = newStart->prev = nullptr;

  last_node->next = start;
  start->prev = last_node;

  return newStart;
}