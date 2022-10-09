// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node *next;

  node(int x) {
    data = x;
    next = NULL;
  }
};

node *solve(node *head, node *end) {
  // base case
  if (head == end or head->next == end) return head;

  // paritioning
  auto pivot = head, temp = head;
  while (temp->next != end) {
    if (temp->next->data <= pivot->data) {
      auto t1 = temp->next;
      temp->next = t1->next;
      t1->next = head;
      head = t1;
    } else {
      temp = temp->next;
    }
  }

  // recursive calls
  head = solve(head, pivot);
  pivot->next = solve(pivot->next, end);

  return head;
}

void quickSort(struct node **headRef) { *headRef = solve(*headRef, nullptr); }

int main(int argc, char const *argv[]) { return 0; }
