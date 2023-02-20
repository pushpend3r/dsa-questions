// https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data, height;
  Node *left, *right;
  Node(int x) {
    data = x;
    height = 1;
    left = right = NULL;
  }
};

int height(Node *node) { return node ? node->height : 0; }

Node *LeftRotation(Node *node) {
  if (!node) return nullptr;

  auto left = node->left;
  auto right = node->right;

  node->right = right->left;
  right->left = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  right->height = max(height(right->left), height(right->right)) + 1;

  return right;
}

Node *RightRotation(Node *node) {
  if (!node) return nullptr;

  auto left = node->left;
  auto right = node->right;

  node->left = left->right;
  left->right = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  left->height = max(height(left->left), height(left->right)) + 1;

  return left;
}

int getBalancingFactor(Node *node) {
  if (!node) return 0;
  return height(node->left) - height(node->right);
}

Node *deleteNode(Node *node, int data) {
  if (!node) return nullptr;

  // delete current node
  if (node->data == data) {
    // internal node
    if (node->left or node->right) {
      if (!node->left) return node->right;
      if (!node->right) return node->left;

      // both childrens are present
      auto temp = node->right;
      while (temp->left) temp = temp->left;
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
    // leaf node
    else
      return nullptr;
  }
  // go to right side
  else if (node->data < data)
    node->right = deleteNode(node->right, data);
  // go to left side
  else
    node->left = deleteNode(node->left, data);

  int left_height = height(node->left);
  int right_height = height(node->right);
  node->height = max(left_height, right_height) + 1;

  int balancingFactor = left_height - right_height;

  // if bf is > 1 means left side has more nodes than right side
  if (balancingFactor > 1) {
    if (getBalancingFactor(node->left) >= 0) {
      return RightRotation(node);
    } else {
      node->left = LeftRotation(node->left);
      return RightRotation(node);
    }
  }
  if (balancingFactor < -1) {
    if (getBalancingFactor(node->right) <= 0) {
      return LeftRotation(node);
    } else {
      node->right = RightRotation(node->right);
      return LeftRotation(node);
    }
  }

  return node;
}