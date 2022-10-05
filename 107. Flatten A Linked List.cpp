// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

Node *mergeTwoSortedLists(Node *first, Node *second) {
  if (!first) return second;
  if (!second) return first;

  if (first->data > second->data) swap(first, second);

  Node *tempFirst = first, *tempSecond = second;

  while (tempFirst->bottom and tempSecond) {
    if (tempFirst->data <= tempSecond->data and
        tempSecond->data <= tempFirst->bottom->data) {
      Node *bottom = tempSecond->bottom;
      tempSecond->bottom = tempFirst->bottom;
      tempFirst->bottom = tempSecond;
      tempSecond = bottom;
    }
    tempFirst = tempFirst->bottom;
  }

  if (tempSecond) tempFirst->bottom = tempSecond;

  return first;
}

Node *flatten(Node *root) {
  // Base condition
  if (!root or !root->next) return root;
  Node *first = root, *second = flatten(root->next);
  return mergeTwoSortedLists(first, second);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
