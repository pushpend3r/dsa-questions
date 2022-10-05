// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

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

void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
  Node *slow = head, *fast = head;

  while (fast->next != head and fast->next->next != head) {
    fast = fast->next->next;
    slow = slow->next;
  }

  if (fast->next != head) fast = fast->next;

  *head2_ref = slow->next;
  fast->next = *head2_ref;

  slow->next = head;
  *head1_ref = head;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
