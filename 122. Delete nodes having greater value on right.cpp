// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *reverse(Node *prev, Node *current) {
  if (!current) return prev;
  Node *next = current->next;
  current->next = prev;
  return reverse(current, next);
}

// Approach 1
Node *compute(Node *head) {
  head = reverse(nullptr, head);
  auto temp = head;
  while (temp->next) {
    if (temp->data > temp->next->data) {
      auto next = temp->next;
      temp->next = temp->next->next;
      next->next = nullptr;
      delete next;
    } else {
      temp = temp->next;
    }
  }
  head = reverse(nullptr, head);
  return head;
}

// Approach 2
Node *compute(Node *head) {
  // reached beyond the last node
  if (!head) return nullptr;

  // getting what is next node
  Node *next = compute(head->next);

  // head is the last node
  if (!next) return head;

  // if next node is bigger than current (head) than delete the head node
  if (head->data < next->data)
    head = next;
  else
    head->next = next;

  return head;
}