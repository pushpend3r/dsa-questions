// https://practice.geeksforgeeks.org/problems/level-order-traversal/1
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

int total_levels(Node* root, int count = -1) {
  if (!root) return count;
  count++;
  return max(total_levels(root->left, count), total_levels(root->right, count));
}

void getGivenLevelNodeValues(Node* node, int level, vector<int>& ans) {
  if (!node) return;

  if (level == 0) {
    ans.push_back(node->data);
    return;
  }

  getGivenLevelNodeValues(node->left, level - 1, ans);
  getGivenLevelNodeValues(node->right, level - 1, ans);
}

// With Recursion - TC - O(N ^ 2)
vector<int> levelOrder(Node* node) {
  int levels = total_levels(node);
  vector<int> ans;

  for (int level = 0; level <= levels; ++level) {
    vector<int> currentLevelNodes;
    getGivenLevelNodeValues(node, level, currentLevelNodes);
    ans.insert(ans.end(), currentLevelNodes.begin(), currentLevelNodes.end());
  }

  return ans;
}

// With Queue - TC O(N)
vector<int> levelOrder(Node* node) {
  if (!node) return {};

  queue<Node*> q;
  vector<int> ans;

  q.push(node);

  while (q.empty() == false) {
    Node* temp = q.front();
    q.pop();

    ans.push_back(temp->data);

    if (temp->left) q.push(temp->left);
    if (temp->right) q.push(temp->right);
  }

  return ans;
}