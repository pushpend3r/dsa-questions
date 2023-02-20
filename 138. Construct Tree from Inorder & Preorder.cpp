// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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

Node* ans(int pre[], int& preStart, int preEnd, int in[], int inStart,
          int inEnd) {
  if (preStart > preEnd or inStart > inEnd) return nullptr;

  int data = pre[preStart];
  auto node = new Node(data);
  int pos = findPos(in, data, inStart, inEnd);

  preStart++;

  node->left = ans(pre, preStart, preEnd, in, inStart, pos - 1);
  node->right = ans(pre, preStart, preEnd, in, pos + 1, inEnd);

  return node;
}

Node* buildTree(int in[], int pre[], int n) {
  int preStart = 0;
  return ans(pre, preStart, n - 1, in, 0, n - 1);
}