#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedList {
  // -- Properties
 public:
  int value;
  SinglyLinkedList *next;

  // -- Methods
 public:
  SinglyLinkedList() {
    this->value = 0;
    this->next = nullptr;
  }

  SinglyLinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }

  SinglyLinkedList(int value, SinglyLinkedList *next) {
    this->value = value;
    this->next = next;
  }

  ~SinglyLinkedList() {
    this->value = 0;
    this->next = nullptr;
  }
};

void printLinkedList(SinglyLinkedList *head) {
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

void releaseMemory(SinglyLinkedList *head) {
  if (head == nullptr) return;
  releaseMemory(head->next);
  delete head;
}

void insertByPos(SinglyLinkedList *&head, int pos, SinglyLinkedList *newNode) {
  if (head == nullptr) {
    head = newNode;
    return;
  }

  if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }

  SinglyLinkedList *temp = head;
  int count = 1;
  while (temp != nullptr) {
    if (count == pos - 1) {
      newNode->next = temp->next;
      temp->next = newNode;
      return;
    }
    count++;
    temp = temp->next;
  }

  cout << "Invalid Pos" << endl;
  return;
}

void deleteByPos(SinglyLinkedList *&head, int pos) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  if (pos == 1) {
    SinglyLinkedList *temp = head;
    head = head->next;
    releaseMemory(temp);
    return;
  }

  SinglyLinkedList *temp = head;
  int count = 1;
  while (temp != nullptr) {
    if (count == pos - 1) {
      SinglyLinkedList *nodetoBedeleted = temp->next;
      temp->next = nodetoBedeleted->next;
      releaseMemory(nodetoBedeleted);
      return;
    }

    count++;
    temp = temp->next;
  }

  cout << "Invalid pos" << endl;
  return;
}

void deleteBykey(SinglyLinkedList *&head, int key) {
  if (head == nullptr) return;

  if (head->value == key) {
    SinglyLinkedList *temp = head;
    head = head->next;
    releaseMemory(temp);
  }

  SinglyLinkedList *temp = head;
  while (temp->next != nullptr) {
    if (temp->next->value == key) {
      SinglyLinkedList *temp2 = temp->next;
      temp->next = temp2->next;
      releaseMemory(temp2);
      return;
    }
    temp = temp->next;
  }
}

SinglyLinkedList *search(SinglyLinkedList *&head, int key) {
  SinglyLinkedList *temp = head;

  while (temp != nullptr) {
    if (temp->value == key) return temp;
    temp = temp->next;
  }

  return nullptr;
}

int main(int argc, char const *argv[]) {
  SinglyLinkedList *head = nullptr;

  insertByPos(head, 1, new SinglyLinkedList(1));
  insertByPos(head, 1, new SinglyLinkedList(2));
  printLinkedList(head);
  deleteBykey(head, 1);

  releaseMemory(head);
  return 0;
}
