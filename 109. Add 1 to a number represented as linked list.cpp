// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

int solve(Node* head) {
  // base case
  if (!head) return 1;
  int newValue = head->data + solve(head->next);
  head->data = newValue % 10;
  return newValue / 10;
}

// Approach 1
Node* addOne(Node* head) {
  int carry = solve(head);
  if (!carry) return head;
  auto newNode = new Node(carry);
  newNode->next = head;
  return newNode;
}

Node* reverse(Node* head, Node* prev) {
  if (!head) return prev;
  Node* next = head->next;
  head->next = prev;
  return reverse(next, head);
}

// Approach 2
Node* addOne(Node* head) {
  // reverse
  head = reverse(head, nullptr);

  int carry = 1;
  auto temp = head;
  while (temp) {
    int newValue = temp->data + carry;
    temp->data = newValue % 10;
    carry = newValue / 10;
    temp = temp->next;
  }

  // reverse
  head = reverse(head, nullptr);

  if (carry) {
    auto newHead = new Node(carry);
    newHead->next = head;
    head = newHead;
  }

  return head;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
