// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(T data) {
    next = NULL;
    this->data = data;
  }

  ~Node() {
    if (next != NULL) {
      delete next;
    }
  }
};

// Approach 1
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
  auto temp = new Node<int>(-1);
  auto current = temp;

  while (first != nullptr and second != nullptr) {
    // Min Node between first and second
    Node<int>* minNode;
    if (first->data < second->data) {
      minNode = first;
      first = first->next;
    } else {
      minNode = second;
      second = second->next;
    }

    current->next = minNode;
    current = current->next;
  }

  if (first != nullptr)
    current->next = first;
  else
    current->next = second;

  return temp->next;
}

Node<int>* solve(Node<int>* a, Node<int>* b) {
  /*
    a = -------------
    b =   -------------

    --OR--
    a = ------------
    b =   --------

    a->data <= b->data
  */
  auto head = a, curr_a = a, curr_b = b;
  while (curr_a->next != nullptr and curr_b != nullptr) {
    auto b_next = curr_b->next;
    auto b_data = curr_b->data;
    auto a_data = curr_a->data;
    auto a_next_data = curr_a->next->data;

    if (a_data <= b_data and b_data <= a_next_data) {
      curr_b->next = curr_a->next;
      curr_a->next = curr_b;
      curr_b = b_next;
    }

    curr_a = curr_a->next;
  }

  if (curr_b != nullptr) curr_a->next = curr_b;

  return head;
}

// Approach 2
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
  if (first == nullptr) return second;
  if (second == nullptr) return first;

  if (first->data <= second->data)
    return solve(first, second);
  else
    return solve(second, first);
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
