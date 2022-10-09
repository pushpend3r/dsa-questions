//  https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *next, *prev;
  Node(int val) : data(val), next(NULL), prev(NULL) {}
};

Node *lastNode(Node *head) {
  if (!head) return nullptr;
  while (head->next) head = head->next;
  return head;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
  vector<pair<int, int>> ans;
  auto end = lastNode(head);

  while (head != end and head->prev != end) {
    int sum = head->data + end->data;

    if (sum == target) {
      ans.push_back(make_pair(head->data, end->data));
      head = head->next;
      end = end->prev;
    } else if (sum < target)
      head = head->next;
    else
      end = end->prev;
  }
  return ans;
}