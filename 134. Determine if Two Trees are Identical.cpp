// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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

bool isIdentical(Node* r1, Node* r2) {
  // both nodes are null
  if (!r1 and !r2) return true;
  // either one of them is null
  if (!!r1 ^ !!r2) return false;
  // none of them is null
  return r1->data == r2->data and isIdentical(r1->left, r2->left) and
         isIdentical(r1->right, r2->right);
}