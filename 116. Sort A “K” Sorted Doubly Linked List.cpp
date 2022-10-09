// https://www.codingninjas.com/codestudio/problems/sort-a-k-sorted-doubly-linked-list_1118118

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *prev;
  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

Node *sortedDll(Node *head, int k) {}