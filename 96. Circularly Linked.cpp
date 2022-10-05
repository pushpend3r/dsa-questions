// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232

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

// Approach 1 - TLE 😔
bool isCircular(Node* head) {
  if (head == nullptr) return true;
  Node* temp = head->next;
  unordered_map<Node*, bool> map;
  while (temp != head and temp != nullptr) {
    if (map.find(temp) != map.end()) return false;
    map[temp] = true;
    temp = temp->next;
  }
  if (temp == nullptr) return false;
  return true;
}

// Approach 2 - Floyd’s slow and fast pointers
bool isCircular(Node* head) {
  if (head == nullptr) return true;
  if (head->next == nullptr) return false;
  // this slow and fast pointer approach is Floyd’s slow and fast pointers
  // we could start slow and fast from different places but benefit of starting
  // thme as same position is that whenever cycle is detected, they will be on
  // the same point where they started
  Node *slow = head, *fast = head;
  while (fast != nullptr and fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
  }

  // Whenever slow == fast, then we know there is a cycle.
  if (slow == fast and slow == head) return true;
  return false;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
