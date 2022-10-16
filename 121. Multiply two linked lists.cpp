// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

long long listToInt(Node* head, long long& value) {
  if (!head) return 1;
  long long baseValue = listToInt(head->next, value);
  value = (value + (head->data * baseValue) % MOD) % MOD;
  return (baseValue * 10) % MOD;
}

// Approach 1
long long multiplyTwoLists(Node* l1, Node* l2) {
  long long value1, value2;
  value1 = value2 = 0;

  listToInt(l1, value1);
  listToInt(l2, value2);

  return (value1 * value2) % MOD;
}

// Approach 2
long long multiplyTwoLists(Node* l1, Node* l2) {
  long long value1 = 0, value2 = 0;

  while (l1) {
    value1 = (value1 * 10) % MOD + l1->data;
    l1 = l1->next;
  }

  while (l2) {
    value2 = (value2 * 10) % MOD + l2->data;
    l2 = l2->next;
  }

  return (value1 * value2) % MOD;
}