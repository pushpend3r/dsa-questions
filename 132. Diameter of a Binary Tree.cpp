// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
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

// Diameter of any node = height of left subtree + height of right subtree + 1;
int func_ans(Node* node, int& ans) {
  if (!node) return 0;
  int left_h = func_ans(node->left, ans);
  int right_h = func_ans(node->right, ans);
  int diameter = left_h + right_h + 1;
  if (diameter > ans) ans = diameter;
  return max(left_h, right_h) + 1;
}

int diameter(Node* root) {
  int ans;
  func_ans(root, ans);
  return ans;
}