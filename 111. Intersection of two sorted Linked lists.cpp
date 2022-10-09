// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

Node* findIntersection(Node* head1, Node* head2) {
  auto head = new Node(-1), temp = head;

  while (head1 and head2) {
    if (head1->data == head2->data) {
      temp->next = new Node(head1->data);
      temp = temp->next;
      head1 = head1->next;
      head2 = head2->next;
    } else if (head1->data < head2->data) {
      head1 = head1->next;
    } else {
      head2 = head2->next;
    }
  }

  return head->next;
}
