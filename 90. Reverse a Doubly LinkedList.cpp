// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
  Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

// Approach 1
Node *solve(Node *prev, Node *current) {
  if (current == nullptr) return prev;
  Node *next = current->next;
  current->next = prev;
  current->prev = next;
  return solve(current, next);
}

Node *reverseDLL(Node *head) {
  if (head == nullptr) return nullptr;
  return solve(head->prev, head);
}

// Approach 2
Node *reverseDLL(Node *head) {
  if (head == nullptr) return nullptr;
  Node *prev = head->prev, *current = head, *next;
  while (current != nullptr) {
    next = current->next;
    current->prev = next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
