// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

#include <bits/stdc++.h>

using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) {
  if (myStack.empty()) {
    myStack.push(x);
    return myStack;
  }

  auto top = myStack.top();
  myStack.pop();

  pushAtBottom(myStack, x);
  myStack.push(top);

  return myStack;
}