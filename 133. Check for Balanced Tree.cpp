// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

// pair.first = node is balanced or not
// pair.second = height of that node.
pair<bool, int> ans(Node* node) {
  if (!node) return {true, 0};
  auto left = ans(node->left);
  auto right = ans(node->right);
  return {left.first && right.first && abs(left.second - right.second) <= 1,
          max(left.second, right.second) + 1};
}

bool isBalanced(Node* root) { return ans(root).first; }