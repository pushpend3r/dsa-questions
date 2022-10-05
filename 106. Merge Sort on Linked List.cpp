// https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int data;
  node *next;
  node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

node *getMid(node *head) {
  node *slow = head, *fast = head->next;
  while (fast and fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

node *mergeTwoSortedLists(node *first, node *second) {
  if (!first) return second;
  if (!second) return first;

  if (first->data > second->data) swap(first, second);

  node *tempFirst = first, *tempSecond = second;

  while (tempFirst->next and tempSecond) {
    if (tempFirst->data <= tempSecond->data and
        tempSecond->data <= tempFirst->next->data) {
      node *next = tempSecond->next;
      tempSecond->next = tempFirst->next;
      tempFirst->next = tempSecond;
      tempSecond = next;
    }
    tempFirst = tempFirst->next;
  }

  if (tempSecond) tempFirst->next = tempSecond;

  return first;
}

node *mergeSort(node *head) {
  // base case
  if (!head or !head->next) return head;

  node *midNode = getMid(head);
  node *first = head, *second = midNode->next;
  midNode->next = nullptr;

  // recursive calls
  first = mergeSort(first);
  second = mergeSort(second);

  return mergeTwoSortedLists(first, second);
}

void print(node *head) {
  if (!head) return;
  cout << head->data << " ";
  print(head->next);
}

int main(int argc, char const *argv[]) {
  node *head = new node(1);
  head->next = new node(4);
  head->next->next = new node(1);

  print(head);
  head = mergeSort(head);
  print(head);

  return 0;
}
