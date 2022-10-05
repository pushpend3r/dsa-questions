// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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

// Approach 1
struct Node* addTwoLists(struct Node* first, struct Node* second) {
  // util funcs
  auto getData = [&](Node* node) {
    if (node == nullptr) return 0;
    return node->data;
  };

  auto moveToNext = [&](Node*& node) {
    if (node != nullptr) node = node->next;
  };

  auto reverse = [&](Node* node) {
    Node *current = node, *prev = nullptr, *next;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  };

  // Reverse the lists
  first = reverse(first);
  second = reverse(second);

  // calculations
  int carry = 0;
  Node* head = new Node(0);
  Node* temp = head;

  while (carry or first or second) {
    carry = carry + getData(first) + getData(second);

    temp->data = carry % 10;
    temp->next = new Node(0);
    temp = temp->next;

    carry /= 10;

    moveToNext(first);
    moveToNext(second);
  }

  return reverse(head)->next;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
