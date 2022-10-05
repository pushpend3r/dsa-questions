// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *arb;

  Node(int x) {
    data = x;
    next = arb = nullptr;
  }
};

Node *cloneTheList(Node *head) {
  Node *clone_head = new Node(-1);
  Node *temp = clone_head;

  while (head) {
    temp->next = new Node(head->data);
    temp = temp->next;
    head = head->next;
  }

  return clone_head->next;
}

// Approach 1
Node *copyList(Node *head) {
  vector<int> distance;
  Node *temp = head;
  int count = 0, index = 0;

  // Cloning the list (random pointer will stay nullptr)
  Node *cloneList = cloneTheList(head);

  // counting distance from random pointer. (assuming original list is circular)
  while (temp) {
    count = 0;
    Node *temp_node = temp;
    while (temp_node != temp->arb) {
      count++;
      temp_node = temp_node->next;
      if (temp_node == nullptr) temp_node = head;
    }
    distance.push_back(count);
    temp = temp->next;
  }

  // filling right random pointers in clone list
  temp = cloneList;
  while (temp) {
    int current_distance = distance.at(index++);
    auto temp_node = temp;
    while (current_distance--) {
      temp_node = temp_node->next;
      if (temp_node == nullptr) temp_node = cloneList;
    }
    temp->arb = temp_node;
    temp = temp->next;
  }

  return cloneList;
}

// Approach 2 - using Map
Node *copyList2(Node *head) {
  // clone the list (random pointer will be nullptr)
  Node *cloneList = cloneTheList(head);

  // mapping between old and new nodes
  unordered_map<Node *, Node *> map;
  Node *temp_original = head;
  Node *temp_cloned = cloneList;
  while (temp_original) {
    map[temp_original] = temp_cloned;
    temp_original = temp_original->next;
    temp_cloned = temp_cloned->next;
  }

  // filling the random pointers
  temp_original = head;
  while (temp_original) {
    map[temp_original]->arb = map[temp_original->arb];
    temp_original = temp_original->next;
  }

  return cloneList;
}

// Approach 3
Node *copyList3(Node *head) {
  // cloning the list (except random pointer will be nullptr)
  Node *clonedList = cloneTheList(head);

  // mapping
  /*
  OG - 1->2->3
  CL - 1->2->3
  after mapping
  OG - 1  2  3
       |/ |/ |
  CL - 1  2  3
  basically we are
  temp = og->next
  og->next = cl
  cl->next = temp;
  see video for more info -
  https://youtu.be/83mPr0i56Gg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&t=2065
  */
  Node *t_og = head, *t_cl = clonedList;
  while (t_og) {
    Node *a = t_cl->next;
    t_cl->next = t_og->next;
    t_og->next = t_cl;
    t_og = t_og->next->next;
    t_cl = a;
  }

  // Setting random pointer
  t_og = head;
  while (t_og) {
    // Remember arb can be null too..
    if (t_og->arb) t_og->next->arb = t_og->arb->next;
    t_og = t_og->next->next;
  }

  // remove the mapping
  t_og = head;
  while (t_og) {
    Node *a = t_og->next->next;
    if (a) t_og->next->next = a->next;
    t_og->next = a;
    t_og = t_og->next;
  }

  return clonedList;
}

void printAddress(Node *head) {
  if (head == nullptr) return;
  cout << endl;
  cout << head << '(' << head->data << ")\t";
  cout << head->next << '\t' << head->arb << endl;
  printAddress(head->next);
}

int main(int argc, char const *argv[]) {
  Node *head = nullptr;
  head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);

  head->arb = head->next->next;
  head->next->arb = head;
  head->next->next->arb = head->next;

  Node *clonedList = copyList3(head);

  printAddress(head);
  printAddress(clonedList);

  return 0;
}
