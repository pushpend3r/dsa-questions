// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

// except leaf node (who has no left and right children)
void getAllLeftNodes(Node *node, vector<int> &ans) {
  if (!node or (!node->left and !node->right)) return;
  ans.push_back(node->data);
  getAllLeftNodes(node->left, ans);
}

void getAllLeafNodes(Node *node, vector<int> &ans) {
  if (!node) return;
  getAllLeafNodes(node->left, ans);
  getAllLeafNodes(node->right, ans);
  if (!node->left and !node->right) ans.push_back(node->data);
}

// except leaf nodes
void getAllRightNodes(Node *node, vector<int> &ans) {
  if (!node or (!node->left and !node->right)) return;
  getAllRightNodes(node->right, ans);
  ans.push_back(node->data);
}

vector<int> boundary(Node *root) {
  vector<int> ans;
  getAllLeftNodes(root, ans);
  getAllLeafNodes(root, ans);
  getAllRightNodes(root->right, ans);
  return ans;
}