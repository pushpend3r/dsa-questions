// https://www.codingninjas.com/codestudio/problems/count-triplets-in-a-sorted-doubly-linked-list-whose-sum-is-equal-to-a-given-value-x_985286

#include <bits/stdc++.h>

using namespace std;

class DLLNode {
 public:
  int data;
  DLLNode *next;
  DLLNode *prev;
};

DLLNode *lastNode(DLLNode *head) {
  if (!head) return nullptr;
  while (head->next) head = head->next;
  return head;
}

int countTriplets(DLLNode *head, int x) {
  int count = 0;
  auto end = lastNode(head);
  while (head) {
    if (head->data >= x) break;

    // rest is similar as question no 114
    int requiredSum = x - head->data;
    // remember t1 could be nullptr
    auto t1 = head->next, t2 = end;
    while (t1 != t2 and t2->next != t1) {
      int sum = t1->data + t2->data;
      if (sum == requiredSum) {
        count++;
        t1 = t1->next;
        t2 = t2->prev;
      } else if (sum < requiredSum) {
        t1 = t1->next;
      } else {
        t2 = t2->prev;
      }
    }

    head = head->next;
  }
  return count;
}