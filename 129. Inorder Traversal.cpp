// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void inorder(TreeNode *node, vector<int> &ans) {
  if (!node) return;
  inorder(node->left, ans);
  ans.push_back(node->val);
  inorder(node->right, ans);
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;
  inorder(root, ans);
  return ans;
}

// without recursion
vector<int> inorderTraversal(TreeNode *root) {
  if (!root) return {};

  vector<int> ans;
  stack<TreeNode *> s;
  s.push(root);
  auto current_node = root->left;

  while (current_node or s.empty() == false) {
    // going to left side
    while (current_node) {
      s.push(current_node);
      current_node = current_node->left;
    }

    auto temp = s.top();
    ans.push_back(temp->val);
    s.pop();

    current_node = temp->right;
  }

  return ans;
}

// using Morris Traversal
// https://www.youtube.com/watch?v=80Zug6D1_r4
vector<int> inorderTraversal(TreeNode *root) {
  if (!root) return {};

  vector<int> ans;
  auto current_node = root;

  while (current_node) {
    if (current_node->left == nullptr) {
      ans.push_back(current_node->val);
      current_node = current_node->right;
    } else {
      auto temp = current_node->left;
      while (temp->right and temp->right != current_node) temp = temp->right;

      if (temp->right == nullptr) {
        temp->right = current_node;
        current_node = current_node->left;
      } else {
        temp->right = nullptr;
        ans.push_back(current_node->val);
        current_node = current_node->right;
      }
    }
  }

  return ans;
}