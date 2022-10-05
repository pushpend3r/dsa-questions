// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0

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

// Approach 1
Node *sortList(Node *head) {
  int counts[3] = {};
  int index = 0;

  // counting 0's, 1's and 2's
  Node *temp = head;
  while (temp != nullptr) {
    counts[temp->data]++;
    temp = temp->next;
  }

  temp = head;
  while (temp != nullptr) {
    if (counts[index] == 0) index++;
    temp->data = index;
    counts[index]--;
    temp = temp->next;
  }

  return head;
}

// Approach 2
Node *sortList(Node *head) {
  Node *heads[3] = {};
  Node *tails[3] = {};

  Node *temp = head;
  while (temp != nullptr) {
    Node *next = temp->next;
    if (heads[temp->data] != nullptr) {
      temp->next = heads[temp->data];
      heads[temp->data] = temp;
    } else {
      heads[temp->data] = tails[temp->data] = temp;
      temp->next = nullptr;
    }
    temp = next;
  }

  // linking tails to next's heads
  for (int i = 0; i < 2; ++i)
    if (tails[i] != nullptr) tails[i]->next = heads[i + 1];

  // finding first head that is not nullptr
  for (int i = 0; i < 3; ++i)
    if (heads[i] != nullptr) {
      head = heads[i];
      break;
    }

  return head;
}

int main(int argc, char const *argv[]) { return 0; }
