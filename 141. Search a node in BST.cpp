// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int data) { this->data = data; }
};

bool search(Node *root, int &x) {
  if (!root) return false;
  if (root->data < x) return search(root->right, x);
  if (root->data > x) return search(root->left, x);
  return true;
}