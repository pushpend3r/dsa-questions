// https://practice.geeksforgeeks.org/problems/sum-tree/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

pair<bool, long long> ans(Node *node) {
  // node is null
  if (!node) return {true, 0};

  // leaf node
  if (!node->left and !node->right) return {true, node->data};

  auto left = ans(node->left);
  auto right = ans(node->right);

  return {
      node->data == left.second + right.second and left.first and right.first,
      node->data + left.second + right.second};
}

bool isSumTree(Node *root) { return ans(root).first; }