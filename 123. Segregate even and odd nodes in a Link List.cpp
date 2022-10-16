// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void addToTail(Node *&tail, Node *newNode) {
  if (!tail) {
    tail = newNode;
    tail->next = nullptr;
    return;
  }
  newNode->next = tail;
  tail = newNode;
}

Node *reverse(Node *prev, Node *current) {
  if (!current) return prev;
  Node *next = current->next;
  current->next = prev;
  return reverse(current, next);
}

// Approach 1
Node *divide(int N, Node *head) {
  Node *oddTail = nullptr, *evenTail = nullptr;

  auto temp = head;
  while (temp) {
    auto next = temp->next;
    if (temp->data & 1)
      addToTail(oddTail, temp);
    else
      addToTail(evenTail, temp);
    temp = next;
  }

  Node *evenHead = reverse(nullptr, evenTail),
       *oddHead = reverse(nullptr, oddTail);

  if (!evenHead)
    evenHead = oddHead;
  else
    evenTail->next = oddHead;

  return evenHead;
}

// Approach 2
Node *divide(int N, Node *head) {
  Node *evenHead = new Node(-1), *oddHead = new Node(-1);
  Node *evenTail = evenHead, *oddTail = oddHead;

  auto temp = head;
  while (temp) {
    auto next = temp->next;
    if (temp->data & 1) {
      oddTail->next = temp;
      oddTail = temp;
    } else {
      evenTail->next = temp;
      evenTail = temp;
    }
    temp->next = nullptr;
    temp = next;
  }

  oddHead = oddHead->next;
  evenHead = evenHead->next;

  (!evenHead ? evenHead = oddHead : evenTail->next = oddHead);

  return evenHead;
}