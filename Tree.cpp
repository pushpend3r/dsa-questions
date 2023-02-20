#include <bits/stdc++.h>

using namespace std;

/*
Tree is the data structure that has n child

node {
  int data;
  list<node *> children;
}

Binary Tree are Tree where children count is n <= 2

node {
  int data;
  node * left;
  node *right;
}

Terms -
Node
Root
Children
Ansestors
Desendents
Leaf
Parent
Siblings
*/

class Node {
 public:
  int data;
  Node *left;
  Node *right;

  // constructor
  Node(int data, Node *left = nullptr, Node *right = nullptr) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

Node *BuildTree() {
  int data;
  cin >> data;
  if (data == -1) return nullptr;
  Node *node = new Node(data);
  cout << "Enter Left Number of " << data << endl;
  node->left = BuildTree();
  cout << "Enter Right Number of " << data << endl;
  node->right = BuildTree();
  return node;
}

/**
 * @brief
 * Print Level Order / Breath First Traversal
 * We used NULLPTR as a seperator to know level ends
 * Note - we didn't put child node's NULLPTR. every time NULLPTR comes we know
 * level has ended.
 *
 * using Queues
 * @param root
 */
void LevelOrderTraversalUsingQueue(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(nullptr);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();
    if (!temp) {
      cout << endl;
      if (!q.empty()) q.push(nullptr);
    } else {
      cout << temp->data << " ";
      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
    }
  }
}

int height(Node *root, int count = 0) {
  if (!root) return count;
  count++;
  return max(height(root->left, count), height(root->right, count));
}

/**
 * @brief Reversal of Level Order Traversal
 *
 * @param root
 */
void ReverseLevelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(nullptr);

  vector<Node *> arr;

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();
    if (!temp) {
      arr.push_back(nullptr);
      if (!q.empty()) q.push(nullptr);
    } else {
      arr.push_back(temp);
      if (temp->right) q.push(temp->right);
      if (temp->left) q.push(temp->left);
    }
  }

  reverse(arr.begin(), arr.end());

  for (const auto &i : arr) {
    if (i)
      cout << i->data << " ";
    else
      cout << "\n";
  }
  cout << endl;
}

// LNR - Left Node Right
void InOrderTraversal(Node *node) {
  if (!node) return;
  InOrderTraversal(node->left);
  cout << node->data << " ";
  InOrderTraversal(node->right);
  cout << endl;
}

int main(int argc, char const *agv[]) {
  Node *root = BuildTree();
  cout << height(root) << endl;
  LevelOrderTraversalUsingQueue(root);
  // ReverseLevelOrderTraversal(root);
  return 0;
}
