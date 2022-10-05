// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node* kReverse(Node* head, int k) {
  // Base case
  if (head == nullptr) return nullptr;

  Node *prev = nullptr, *current = head, *next;
  int temp_k = k;

  while (current != nullptr and temp_k--) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  // prev = our new head, current = next group head, head = tail of current
  // group

  head->next = kReverse(current, k);

  return prev;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
