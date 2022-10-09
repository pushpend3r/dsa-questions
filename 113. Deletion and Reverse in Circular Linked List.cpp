// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

void deleteNode(struct Node **_head, int _key) {
  auto &head = *_head, temp = *_head;

  // if LL is empty
  if (!head) return;

  while (temp->next != head) {
    if (temp->next->data == _key) {
      auto next = temp->next->next;
      // OPTIONAL
      temp->next->next = nullptr;
      temp->next = next;
      return;
    }
    temp = temp->next;
  }
}

void reverse(struct Node **_head_ref) {
  auto &head = *_head_ref, temp = head;

  if (!head) return;
  if (head == head->next) return;

  Node *current = head->next, *prev = head;

  while (current != head) {
    auto next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head->next = prev;
  head = prev;
}
