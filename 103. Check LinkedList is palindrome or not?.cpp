// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

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

bool solve(Node *node, Node *&head) {
  if (node == nullptr) return true;
  if (solve(node->next, head) and node->data == head->data) {
    head = head->next;
    return true;
  }
  return false;
}

// Approach 1 - TC -> O(N), SC -> O(N)
bool isPalindrome(Node *head) { return solve(head, head); }

Node *reverse(Node *head) {
  Node *current = head, *prev = nullptr, *next;
  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

Node *getMiddle(Node *head) {
  Node *slow = head, *fast = head->next;
  while (fast and fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

bool isEqual(Node *l1, Node *l2) {
  while (l2) {
    if (l1->data != l2->data) return false;
    l1 = l1->next;
    l2 = l2->next;
  }
  return true;
}

// Approach 2 -- TC -> O(N) and SC -> O(1)
bool isPalindrome(Node *head) {
  Node *middle = getMiddle(head);
  middle->next = reverse(middle->next);
  if (isEqual(head, middle->next)) {
    // OPTIONAL
    middle->next = reverse(middle->next);
    return true;
  } else {
    return false;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
