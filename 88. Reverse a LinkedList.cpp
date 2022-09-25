// https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1
void insertAtHead(ListNode *&head, int value) {
  ListNode *newNode = new ListNode(value);
  newNode->next = head;
  head = newNode;
}

ListNode *reverseList(ListNode *head) {
  ListNode *reverserListHead = nullptr;
  while (head != nullptr) {
    insertAtHead(reverserListHead, head->val);
    head = head->next;
  }
  return reverserListHead;
}

// Approach 2
// https://leetcode.com/problems/reverse-linked-list/discuss/803955/C%2B%2B-Iterative-vs.-Recursive-Solutions-Compared-and-Explained-~99-Time-~85-Space
ListNode *reverseList(ListNode *head) {
  ListNode *nextNode, *prevNode = nullptr;
  while (head != nullptr) {
    nextNode = head->next;
    head->next = prevNode;
    prevNode = head;
    head = nextNode;
  }
  return prevNode;
}

// Approach 3
ListNode *solve(ListNode *prev, ListNode *head, ListNode *next) {
  if (head == nullptr) return prev;
  next = head->next;
  head->next = prev;
  prev = head;
  head = next;
  return solve(prev, head, next);
}

ListNode *reverseList(ListNode *head) {
  if (head == nullptr) return nullptr;
  return solve(nullptr, head, head->next);
}

// Approach 4
// https://leetcode.com/problems/reverse-linked-list/discuss/58130/C++-Iterative-and-Recursive/323362
ListNode *reverseList(ListNode *head, ListNode *prev = nullptr) {
  if (head == nullptr) return prev;
  ListNode *next = head->next;
  head->next = prev;
  return reverseList(next, head);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
