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

void print(Node *node) {
  if (!node) return;
  cout << node->data << " ";
  print(node->next);
}

void swap(Node *n1, Node *n2) {
  auto n1_prev = n1->prev, n2_next = n2->next;
  if (n1_prev) n1_prev->next = n2;
  if (n2_next) n2_next->prev = n1;

  n2->next = n1;
  n1->prev = n2;

  n1->next = n2_next;
  n2->prev = n1_prev;
}

Node *insertionSort(Node *node) {
  auto current = node;

  while (current->prev and current->prev->data >= current->data)
    swap(current->prev, current);

  if (!current->prev) return current;

  return nullptr;
}

// Approach 1 - O(n * k)
Node *sortedDll(Node *head, int k) {
  // empty or one node
  if (!head or !head->next) return head;

  auto temp = head->next;

  while (temp) {
    auto next = temp->next;
    auto newHead = insertionSort(temp);
    if (newHead) head = newHead;
    temp = next;
  }

  return head;
}