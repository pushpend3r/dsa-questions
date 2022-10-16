// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

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

Node *mergeLists(Node *n1, Node *n2) {
  if (!n1) return n2;
  if (!n2) return n1;

  if (n1->data > n2->data) swap(n1, n2);

  auto head = n1;

  while (n1->next and n2) {
    if (n1->data <= n2->data and n2->data <= n1->next->data) {
      auto next_n1 = n1->next, next_n2 = n2->next;
      n1->next = n2;
      n2->next = next_n1;
      n2 = next_n2;
    }
    n1 = n1->next;
  }

  if (n2) n1->next = n2;

  return head;
}

Node *mergeKLists(Node *arr[], int K) {
  auto head = arr[0];
  for (int i = 1; i < K; ++i) head = mergeLists(head, arr[i]);
  return head;
}
