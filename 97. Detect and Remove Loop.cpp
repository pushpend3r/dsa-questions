// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// For Why Floyd Cycle Detection Algo Works? -
// https://www.youtube.com/watch?v=PvrxZaH_eZ4

Node *isLoopPresent(Node *head) {
  Node *slow = head, *fast = head;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
    if (fast != nullptr) fast = fast->next;
    if (fast == slow) return fast;
  }
  return nullptr;
}

Node *startingPointOfLoop(Node *meetingPoint, Node *head) {
  while (head != meetingPoint) {
    head = head->next;
    meetingPoint = meetingPoint->next;
  }
  return head;
}

Node *removeLoop(Node *head) {
  if (head == nullptr) return nullptr;

  Node *meetingPoint, *startingPointOfLoopNode, *temp;

  meetingPoint = isLoopPresent(head);

  // if loop is not present
  if (meetingPoint == nullptr) return head;

  startingPointOfLoopNode = startingPointOfLoop(meetingPoint, head);

  temp = startingPointOfLoopNode;

  // Finding loop tail node
  while (temp->next != startingPointOfLoopNode) temp = temp->next;

  temp->next = nullptr;

  return head;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
