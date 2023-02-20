// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

void solve(stack<int>& s, int n) {
  if (n == 0) {
    s.pop();
    return;
  }
  int top = s.top();
  s.pop();
  solve(s, --n);
  s.push(top);
}

void deleteMiddle(stack<int>& inputStack, int N) {
  int middleElement = (N + 1) / 2;
  if (N % 2) middleElement--;
  solve(inputStack, middleElement);
}