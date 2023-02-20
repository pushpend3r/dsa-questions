// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node* deleteNode(Node* root, int X) {
  if (!root) return nullptr;

  if (root->data > X)
    root->left = deleteNode(root->left, X);
  else if (root->data < X)
    root->right = deleteNode(root->right, X);
  else {
    // delete current node
    // children are not null
    if (root->left and root->right) {
      auto temp = root->right;
      while (temp->left) temp = temp->left;
      root->data = temp->data;
      root->right = deleteNode(root->right, root->data);
    } else {
      return root->left ? root->left : root->right;
    }
  }

  return root;
}
