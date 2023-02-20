// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875

#include <bits/stdc++.h>

using namespace std;

void pushAtBottom(stack<int>& myStack, int x) {
  if (myStack.empty()) {
    myStack.push(x);
    return;
  }

  auto top = myStack.top();
  myStack.pop();

  pushAtBottom(myStack, x);
  myStack.push(top);
}

void reverseStack(stack<int>& stack) {
  if (stack.empty()) return;
  auto top = stack.top();
  stack.pop();
  reverseStack(stack);
  pushAtBottom(stack, top);
}