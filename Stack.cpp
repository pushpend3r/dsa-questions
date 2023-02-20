#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int value;
  Node* next;
  Node(int value, Node* next = nullptr) {
    this->value = value;
    this->next = next;
  }
};

class StackClass {
 public:
  Node* list;
  int size;

  StackClass() : list(nullptr), size(0) {}

  void pop() {
    if (list == nullptr) {
      cout << "Stack is empty\n";
      return;
    }

    // storing next node
    auto next = list->next;

    // clean up
    list->value = 0;
    list->next = nullptr;
    delete list;

    list = next;
    size--;
  }

  void push(int value) {
    auto newNode = new Node(value);
    newNode->next = list;
    list = newNode;
    size++;
  }

  bool isEmpty() { return size; }

  int getSize() { return size; }

  int top() {
    if (list == nullptr) {
      cout << "Stack is empty\n";
      return -1;
    }

    return list->value;
  }

  // destructor
  ~StackClass() {
    Node* currentNode = list;
    while (currentNode) {
      auto next = currentNode->next;
      currentNode->next = nullptr;
      currentNode->value = 0;
      delete currentNode;
      currentNode = next;
    }
  }
};

int main(int argc, char const* argv[]) {
  StackClass* S = new StackClass();
  S->push(12);
  S->push(13);
  S->push(14);

  cout << S->top() << endl;
  S->pop();

  cout << S->top() << endl;
  S->pop();

  cout << boolalpha << S->isEmpty() << endl;

  cout << S->top() << endl;
  S->pop();

  cout << S->top() << endl;
  S->pop();

  cout << boolalpha << S->isEmpty() << endl;

  return 0;
}
