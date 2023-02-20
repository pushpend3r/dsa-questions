// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int data) { this->data = data; }
};

Node* insert(Node* root, int Key) {
  if (root == nullptr) return new Node(Key);
  if (root->data == Key) return root;
  if (root->data > Key) root->left = insert(root->left, Key);
  if (root->data < Key) root->right = insert(root->right, Key);

  return root;
}