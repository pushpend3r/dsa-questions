// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) { this->data = data; }
};

int findPos(int arr[], int data, int start, int end) {
  for (int i = start; i <= end; ++i) {
    if (arr[i] == data) return i;
  }
  return -1;
}

Node* ans(int in[], int inStart, int inEnd, int post[], int postStart,
          int& postEnd) {
  if (postStart > postEnd or inStart > inEnd) return nullptr;

  int data = post[postEnd--];
  auto node = new Node(data);
  int pos = findPos(in, data, inStart, inEnd);

  node->right = ans(in, pos + 1, inEnd, post, postStart, postEnd);
  node->left = ans(in, inStart, pos - 1, post, postStart, postEnd);

  return node;
}

Node* buildTree(int in[], int post[], int n) {
  int postEnd = n - 1;
  return ans(in, 0, n - 1, post, 0, postEnd);
}