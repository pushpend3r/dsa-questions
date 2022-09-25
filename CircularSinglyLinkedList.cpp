#include <bits/stdc++.h>

using namespace std;

class CircularSinglyLinkedList {
 public:
  int value;
  CircularSinglyLinkedList *next;

  CircularSinglyLinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
  ~CircularSinglyLinkedList() {
    this->next = nullptr;
    this->value = 0;
  }
};

void releaseSingleNodeMemory(CircularSinglyLinkedList *node) {
  if (node == nullptr) return;
  delete node;
}

void releaseMemory(CircularSinglyLinkedList *&tail) {
  if (tail == nullptr) return;
  CircularSinglyLinkedList *temp = tail;
  do {
    CircularSinglyLinkedList *nextNode = temp->next;
    releaseSingleNodeMemory(temp);
    temp = nextNode;
  } while (temp != tail);

  tail = nullptr;
}

void printLinkedList(CircularSinglyLinkedList *&tail) {
  if (tail == nullptr) return;
  CircularSinglyLinkedList *temp = tail;
  do {
    cout << temp->value << " ";
    temp = temp->next;
  } while (temp != tail);
  cout << endl;
}

void insertByKey(CircularSinglyLinkedList *&tail, int key,
                 CircularSinglyLinkedList *newNode) {
  if (tail == nullptr) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }

  CircularSinglyLinkedList *temp = tail;
  do {
    if (temp->value == key) {
      newNode->next = temp->next;
      temp->next = newNode;
      return;
    }

    temp = temp->next;
  } while (temp != tail);
}

void deleteByKey(CircularSinglyLinkedList *&tail, int key) {
  if (tail == nullptr) return;

  CircularSinglyLinkedList *prev = tail, *curr = tail->next;

  while (curr->value != key) {
    // key doesn't exist
    if (curr == tail) return;
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  // if list only contains one element
  if (curr == prev) tail = nullptr;
  if (tail == curr) tail = prev;
  delete curr;
}

int main(int argc, char const *argv[]) {
  CircularSinglyLinkedList *tail = nullptr;
  insertByKey(tail, 1, new CircularSinglyLinkedList(1));
  insertByKey(tail, 1, new CircularSinglyLinkedList(2));
  insertByKey(tail, 1, new CircularSinglyLinkedList(3));
  insertByKey(tail, 3, new CircularSinglyLinkedList(4));
  deleteByKey(tail, 10);
  printLinkedList(tail);
  releaseMemory(tail);
}
