// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

void postOrder(TreeNode *node, vector<int> &ans) {
  if (!node) return;

  postOrder(node->left, ans);
  postOrder(node->right, ans);
  ans.push_back(node->val);
}

// without recursion
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;
  postOrder(root, ans);
  return ans;
}

// w/o recursion
vector<int> postorderTraversal(TreeNode *root) {
  if (!root) return {};

  stack<TreeNode *> s;
  vector<int> ans;
  auto current_node = root;

  // Ideally we should process like Left-Right-Node but we did Node-Right-Left
  while (current_node or s.empty() == false) {
    while (current_node) {
      s.push(current_node);
      ans.push_back(current_node->val);
      current_node = current_node->right;
    }

    current_node = s.top()->left;
    s.pop();
  }

  // to get the final result
  reverse(ans.begin(), ans.end());

  return ans;
}

// Morris Traversal
// We Process like Node-Right-Left and then reverse the ans
vector<int> postorderTraversal(TreeNode *root) {
  if (!root) return {};

  auto current_node = root;
  vector<int> ans;

  while (current_node) {
    if (!current_node->right) {
      ans.push_back(current_node->val);
      current_node = current_node->left;
    } else {
      auto temp = current_node->right;
      while (temp->left and temp->left != current_node) temp = temp->left;
      if (!temp->left) {
        temp->left = current_node;
        ans.push_back(current_node->val);
        current_node = current_node->right;
      } else {
        current_node = current_node->left;
        temp->left = nullptr;
      }
    }
  }

  reverse(ans.begin(), ans.end());

  return ans;
}