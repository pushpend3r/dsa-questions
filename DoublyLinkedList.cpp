#include <bits/stdc++.h>

using namespace std;

class DoublyLinkList {
 public:
  DoublyLinkList *prev;
  int value;
  DoublyLinkList *next;

  DoublyLinkList(int value) {
    this->prev = nullptr;
    this->value = value;
    this->next = nullptr;
  }
  DoublyLinkList(int value, DoublyLinkList *next) {
    this->prev = nullptr;
    this->value = value;
    this->next = next;
  }
  DoublyLinkList(DoublyLinkList *prev, int value, DoublyLinkList *next) {
    this->prev = prev;
    this->value = value;
    this->next = next;
  }
};

void releaseMemory(DoublyLinkList *node) {
  if (node == nullptr) return;
  releaseMemory(node->next);
  node->next = nullptr;
  node->prev = nullptr;
  node->value = 0;
  delete node;
}

void printLinkedList(DoublyLinkList *node) {
  while (node != nullptr) {
    cout << node->value << " ";
    node = node->next;
  }
  cout << endl;
}

void deleteByPos(DoublyLinkList *&head, int pos) {
  if (head == nullptr) return;

  if (pos == 1) {
    DoublyLinkList *temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    temp->next = nullptr;
    releaseMemory(temp);
    return;
  }

  DoublyLinkList *temp = head;
  int count = 1;
  while (temp != nullptr) {
    if (count == pos) {
      DoublyLinkList *currentNode = temp, *prevNode = temp->prev,
                     *nextNode = temp->next;

      if (prevNode != nullptr) prevNode->next = nextNode;
      if (nextNode != nullptr) nextNode->prev = prevNode;

      currentNode->prev = currentNode->next = nullptr;

      releaseMemory(currentNode);

      return;
    }
    count++;
    temp = temp->next;
  }
}

void insertByPos(DoublyLinkList *&head, int pos, DoublyLinkList *newNode) {
  if (head == nullptr) {
    head = newNode;
    return;
  }

  if (pos == 1) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
  }

  DoublyLinkList *temp = head;
  int count = 1;
  while (temp != nullptr) {
    if (count == pos - 1) {
      DoublyLinkList *prevNode = temp, *nextNode = temp->next;
      prevNode->next = newNode;
      newNode->prev = prevNode;
      newNode->next = nextNode;
      if (nextNode != nullptr) nextNode->prev = newNode;
      return;
    }
    count++;
    temp = temp->next;
  }
}

DoublyLinkList *search(DoublyLinkList *&head, int key) {
  DoublyLinkList *temp = head;
  while (temp != nullptr) {
    if (temp->value == key) {
      return temp;
    }
    temp = temp->next;
  }
  return nullptr;
}

int main(int argc, char const *argv[]) {
  DoublyLinkList *head = nullptr;
  insertByPos(head, 1, new DoublyLinkList(1));
  insertByPos(head, 1, new DoublyLinkList(2));
  insertByPos(head, 1, new DoublyLinkList(3));
  printLinkedList(head);
  deleteByPos(head, 2);
  printLinkedList(head);

  releaseMemory(head);
  return 0;
}
