// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581

#include <bits/stdc++.h>

using namespace std;

int nextSmallerElementInStack(stack<int> &s, int &value) {
  // base case
  if (s.top() < value) return s.top();
  s.pop();
  return nextSmallerElementInStack(s, value);
}

vector<int> nextSmallerElement(vector<int> &arr, int n) {
  vector<int> ans(n);

  stack<int> s;
  s.push(-1);

  for (int i = n - 1; i >= 0; --i) {
    ans[i] = nextSmallerElementInStack(s, arr[i]);
    s.push(arr[i]);
  }

  return ans;
}