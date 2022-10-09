// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *lastNode(Node *head) {
  if (!head or !head->next) return head;
  auto temp = head;
  while (temp->next->next != nullptr) temp = temp->next;
  return temp->next;
}

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

// Approach 1
int intersectPoint(Node *head1, Node *head2) {
  if (!head1 or !head2) return -1;

  // Turn LLs into a LL that have a loop in it and we have to find that node
  // from which loop starts similar to question 97
  auto last_Node = lastNode(head1);
  last_Node->next = head2;
  // --

  Node *meetingPoint, *startingPointOfLoopNode;

  meetingPoint = isLoopPresent(head1);

  // if loop is not present
  if (meetingPoint == nullptr) return -1;

  startingPointOfLoopNode = startingPointOfLoop(meetingPoint, head1);

  return startingPointOfLoopNode->data;
}

// Approach 2 - simple but not optimized got TLE and it requires extra space
// too.. although logic is correct
int intersectPoint(Node *head1, Node *head2) {
  unordered_map<Node *, bool> map;

  while (head1) {
    map[head1] = true;
    head1 = head1->next;
  }

  while (head2) {
    if (map.find(head2) != map.end()) return head2->data;
    head2 = head2->next;
  }

  return -1;
}

int nodeCount(Node *head) {
  int count = 0;
  while (head) {
    head = head->next;
    count++;
  }
  return count;
}

Node *ithNode(Node *head, int pos) {
  int i = 0;
  while (pos != i and head) {
    head = head->next;
    i++;
  }
  return head;
}

// Approach 3
int intersectPoint(Node *head1, Node *head2) {
  // count nodes of both LL
  int l1_count = nodeCount(head1), l2_count = nodeCount(head2);

  // making both LL equal so calculation becomes bit easy
  /*
    head1 = 3->6->9->15->30
    head2 = 10->15->30
    intersecting point = 15

    after below
    head1 = 9->15->30
    head2 = 10->15->30
  */
  if (l1_count > l2_count)
    head1 = ithNode(head1, l1_count - l2_count);
  else
    head2 = ithNode(head2, l2_count - l1_count);

  while (head1 and head2) {
    // intersecting point
    if (head1 == head2) return head1->data;
    head1 = head1->next;
    head2 = head2->next;
  }

  return -1;
}

// Approach 4
// Note - it is working on GFG (looks like problem setter doesn't accomodate non
// intersecting case) but it assumes intersection happens if it doesn't
// it will give wrong answer
int intersectPoint(Node *head1, Node *head2) {
  auto l1 = head1, l2 = head2;
  while (l1 != l2) {
    if (l1)
      l1 = l1->next;
    else
      l1 = head2;

    if (l2)
      l2 = l2->next;
    else
      l2 = head1;
  }

  return l1->data;
}

Node *reverseList(Node *head, Node *prev = nullptr) {
  if (head == nullptr) return prev;
  Node *next = head->next;
  head->next = prev;
  return reverseList(next, head);
}

int nodeCount(Node *head) {
  int count = 0;
  while (head) {
    head = head->next;
    count++;
  }
  return count;
}

Node *ithNode(Node *head, int pos) {
  int i = 0;
  while (pos != i and head) {
    head = head->next;
    i++;
  }
  return head;
}

// Approach 5 - using equations
/*
1) Let X be the length of the first linked list until intersection point.
   Let Y be the length of the second linked list until the intersection point.
   Let Z be the length of the linked list from the intersection point to End of
   the linked list including the intersection node.
   We Have
           X + Z = C1;
           Y + Z = C2;
2) Reverse first linked list.
3) Traverse Second linked list. Let C3 be the length of second list - 1.
     Now we have
        X + Y = C3
     We have 3 linear equations. By solving them, we get
       X = (C1 + C3 – C2)/2;
       Y = (C2 + C3 – C1)/2;
       Z = (C1 + C2 – C3)/2; // WE GOT THE INTERSECTION POINT.

See more methods ->
https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
*/
// Note - it is working on GFG (looks like problem setter doesn't accomodate non
// intersecting case) but it assumes intersection happens if it doesn't it will
// give wrong answer
int intersectPoint(Node *head1, Node *head2) {
  int c1 = nodeCount(head1), c2 = nodeCount(head2);
  head1 = reverseList(head1);
  int c3 = nodeCount(head2);
  return ithNode(head1, (c1 + c2 - c3) / 2)->data;
}