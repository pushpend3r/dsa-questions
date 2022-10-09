// https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class LinkedListNode {
 public:
  T data;
  LinkedListNode<T>* next;
  LinkedListNode(T data) {
    this->data = data;
    next = NULL;
  }
};

LinkedListNode<int>* moveToFront(LinkedListNode<int>* head) {
  if (!head or !head->next) return head;
  auto temp = head;
  while (temp->next->next) temp = temp->next;
  auto LastNode = temp->next;
  temp->next = nullptr;
  LastNode->next = head;
  return LastNode;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
