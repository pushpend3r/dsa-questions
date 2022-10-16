// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

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

int length(Node *node) {
  int count = 0;
  while (node) {
    count++;
    node = node->next;
  }
  return count;
}

int ithNode(Node *node, int pos) {
  auto temp = node;
  while (pos-- != 1 and temp) temp = temp->next;
  return temp ? temp->data : -1;
}

// Approach 1
int getNthFromLast(Node *head, int n) {
  return ithNode(head, length(head) - n + 1);
}

int lastNthNodeValue(Node *node, int &n) {
  if (!node) return -1;
  int value = lastNthNodeValue(node->next, n);
  if (n-- == 1) return node->data;
  return value;
}

// Approach 2
// getting **SEGMENTATION FAULT** maybe because of numerous function
// calls that in the end filled the call stack, although logic is correct
int getNthFromLast(Node *head, int n) { return lastNthNodeValue(head, n); }

// Approach 3
int getNthFromLast(Node *head, int n) {
  auto temp = head;

  while (--n and temp) temp = temp->next;

  // n is larger than length of the LL
  if (!temp) return -1;

  while (temp->next) {
    temp = temp->next;
    head = head->next;
  }

  return head->data;
}