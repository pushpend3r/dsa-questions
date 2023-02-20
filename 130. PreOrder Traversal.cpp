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

void preorder(TreeNode *node, vector<int> &ans) {
  if (!node) return;
  ans.push_back(node->val);
  preorder(node->left, ans);
  preorder(node->right, ans);
}

// with recursion
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;
  preorder(root, ans);
  return ans;
}

// w/o recursion
vector<int> preorderTraversal(TreeNode *root) {
  if (!root) return {};

  vector<int> ans;
  stack<TreeNode *> s;
  auto current_node = root;

  while (current_node or s.empty() == false) {
    while (current_node) {
      s.push(current_node);
      ans.push_back(current_node->val);
      current_node = current_node->left;
    }

    current_node = s.top()->right;
    s.pop();
  }

  return ans;
}

// Using Morris Traversal
vector<int> preorderTraversal(TreeNode *root) {
  auto current_node = root;
  vector<int> ans;

  while (current_node) {
    if (!current_node->left) {
      ans.push_back(current_node->val);
      current_node = current_node->right;
    } else {
      auto temp = current_node->left;
      while (temp->right and temp->right != current_node) temp = temp->right;
      if (!temp->right) {
        ans.push_back(current_node->val);
        temp->right = current_node;
        current_node = current_node->left;
      } else {
        current_node = current_node->right;
        temp->right = nullptr;
      }
    }
  }

  return ans;
}