// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

#include <bits/stdc++.h>

using namespace std;

void insertIntoSortedStack(stack<int> &stack, int &value) {
  if (stack.empty() or stack.top() < value) {
    stack.push(value);
    return;
  }

  auto top = stack.top();
  stack.pop();

  insertIntoSortedStack(stack, value);
  stack.push(top);
}

void sortStack(stack<int> &stack) {
  if (stack.empty()) return;
  auto top = stack.top();
  stack.pop();
  sortStack(stack);
  insertIntoSortedStack(stack, top);
}