// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

vector<int> reverseLevelOrder(Node* root) {
  if (!root) return {};

  vector<int> ans;
  ans.reserve(10000);

  queue<Node*> q;
  q.push(root);

  while (q.empty() == false) {
    auto temp = q.front();
    q.pop();
    ans.push_back(temp->data);
    if (temp->right) q.push(temp->right);
    if (temp->left) q.push(temp->left);
  }

  reverse(begin(ans), end(ans));

  return ans;
}