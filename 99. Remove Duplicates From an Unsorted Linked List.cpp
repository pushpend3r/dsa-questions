// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// Approach 1 (using Map)
Node *removeDuplicates(Node *head) {
  if (head == nullptr) return nullptr;
  unordered_map<int, bool> map;
  map[head->data] = true;
  Node *temp = head;
  while (temp != nullptr and temp->next != nullptr) {
    if (map.find(temp->next->data) != map.end()) {
      Node *nodeTobeDelete = temp->next;
      temp->next = temp->next->next;
      delete nodeTobeDelete;
    } else {
      map[temp->next->data] = true;
      temp = temp->next;
    }
  }

  return head;
}

// Approach 2 (getting TLE but logic is correct)
Node *removeDuplicates(Node *head) {
  if (head == nullptr) return nullptr;
  Node *temp = head;
  while (temp != nullptr) {
    Node *temp2 = temp;
    while (temp2->next != nullptr) {
      if (temp2->next->data == temp->data) {
        Node *nodeToBeDelete = temp2->next;
        temp2->next = temp2->next->next;
        delete nodeToBeDelete;
      } else {
        temp2 = temp2->next;
      }
    }
    temp = temp->next;
  }

  return head;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
