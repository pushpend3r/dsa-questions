// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

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

// Approach 1
int height(Node* root, int count = 0) {
  if (!root) return count;
  count++;
  return max(height(root->left, count), height(root->right, count));
}

// Approach 2 - clean and simple
int height(struct Node* node) {
  if (!node) return 0;
  return max(height(node->left), height(node->right)) + 1;
}