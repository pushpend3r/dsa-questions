// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=0

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

Node* uniqueSortedList(Node* head) {
  Node* temp = head;

  while (temp != nullptr and temp->next != nullptr) {
    if (temp->data == temp->next->data) {
      Node* nodeTobBeDelete = temp->next;
      temp->next = temp->next->next;
      delete nodeTobBeDelete;
    } else {
      temp = temp->next;
    }
  }

  return head;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
