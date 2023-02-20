// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

vector<int> zigZagTraversal(Node *root) {
  if (!root) return {};

  queue<Node *> q;
  q.push(root);

  bool flag = true;  // true = left to right, false = right to left
  vector<int> ans;

  while (!q.empty()) {
    int size = q.size();
    vector<int> tempRow(size);

    // this process nodes of the same level, and while they are processing we
    // put next level nodes in the queue too..
    for (int i = 0; i < size; ++i) {
      auto front = q.front();
      q.pop();
      tempRow[flag ? i : size - i - 1] = front->data;

      if (front->left) q.push(front->left);
      if (front->right) q.push(front->right);
    }

    flag = !flag;
    ans.insert(ans.end(), tempRow.begin(), tempRow.end());
  }

  return ans;
}