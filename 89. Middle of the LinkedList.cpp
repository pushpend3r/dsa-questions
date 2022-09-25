// https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

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
int length(Node *head) {
  int count = 0;
  while (head != nullptr) {
    count++;
    head = head->next;
  }
  return count;
}

Node *getNodeByPos(Node *head, int pos) {
  while (head != nullptr) {
    if (pos == 0) {
      return head;
    }
    pos--;
    head = head->next;
  }

  return nullptr;
}

Node *findMiddle(Node *head) {
  int pos = length(head) / 2;
  return getNodeByPos(head, pos);
}

// Approach 2
Node *findMiddle(Node *head) {
  if (head == nullptr or head->next == nullptr) return head;

  Node *fast = head, *slow = head;
  while (fast != nullptr) {
    fast = fast->next;
    if (fast != nullptr)
      fast = fast->next;
    else
      break;
    slow = slow->next;
  }
  return slow;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
