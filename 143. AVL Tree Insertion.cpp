// https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  int height;

  Node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
    this->height = 1;
  }
};

int height(Node* node) { return node ? node->height : 0; }

Node* LeftRotation(Node* node) {
  auto left = node->left;
  auto right = node->right;

  node->right = right->left;
  right->left = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  right->height = max(height(right->left), height(right->right)) + 1;

  return right;
}

Node* RightRotation(Node* node) {
  auto left = node->left;
  auto right = node->right;

  node->left = left->right;
  left->right = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  left->height = max(height(left->left), height(left->right)) + 1;

  return left;
}

Node* insertToAVL(Node* node, int data) {
  // create new node
  if (!node) return new Node(data);

  // node value already exist
  if (node->data == data) return node;

  if (node->data < data)
    node->right = insertToAVL(node->right, data);
  else
    node->left = insertToAVL(node->left, data);

  int left_height = height(node->left);
  int right_height = height(node->right);

  node->height = max(left_height, right_height) + 1;
  int balancingFactor = left_height - right_height;

  // balancing factor is violated...
  if (balancingFactor > 1 or balancingFactor < -1) {
    // false = LEFT and true = RIGHT
    bool direction_1 = node->data < data;
    bool direction_2 =
        direction_1 ? node->right->data < data : node->left->data < data;

    if (direction_1) {
      if (!direction_2) node->right = RightRotation(node->right);
      return LeftRotation(node);
    } else {
      if (direction_2) node->left = LeftRotation(node->left);
      return RightRotation(node);
    }
  }

  return node;
}