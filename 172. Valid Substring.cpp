// https://practice.geeksforgeeks.org/problems/valid-substring0624/1

#include <bits/stdc++.h>

using namespace std;

// approach 1 - using stack TC - O(n), SC - O(n)
int findMaxLen(string str) {
  stack<int> s;
  s.push(-1);

  int ans = 0;
  int n = str.size();

  for (int i = 0; i < n; ++i) {
    char &ch = str.at(i);

    if (ch == ')' and !s.empty() and str[s.top()] == '(')
      s.pop();
    else
      s.push(i);
  }

  s.push(n);

  while (!s.empty()) {
    int top = s.top();
    s.pop();
    if (!s.empty()) ans = max(ans, top - s.top() - 1);
  }

  return ans;
}

// approach 2
int findMaxLen(string str) {
  int openBracketsCount = 0;
  int closeBracketsCount = 0;
  int ans = 0;

  // traverse left to right
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '(')
      openBracketsCount++;
    else
      closeBracketsCount++;

    if (openBracketsCount == closeBracketsCount) {
      ans = max(ans, openBracketsCount + closeBracketsCount);
    }
    // we know for sure that closing bracket we have is no use so we do the
    // reset
    else if (openBracketsCount < closeBracketsCount) {
      openBracketsCount = closeBracketsCount = 0;
    }
  }

  openBracketsCount = closeBracketsCount = 0;

  // traverse right to left
  // we need to traverse again to handle this case - (()(
  for (int i = str.size() - 1; i >= 0; --i) {
    if (str[i] == '(')
      closeBracketsCount++;
    else
      openBracketsCount++;

    if (openBracketsCount == closeBracketsCount) {
      ans = max(ans, openBracketsCount + closeBracketsCount);
    } else if (openBracketsCount < closeBracketsCount) {
      openBracketsCount = closeBracketsCount = 0;
    }
  }

  return ans;
}
