// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473

#include <bits/stdc++.h>

using namespace std;

bool findRedundantBrackets(string &s) {
  stack<bool> stk;
  stk.push(false);

  for (auto &ch : s) {
    if (ch == '(') stk.push(false);

    if (ch == '+' or ch == '/' or ch == '-' or ch == '*') stk.top() = true;

    if (ch == ')') {
      if (!stk.top()) return true;
      stk.pop();
    }
  }

  return false;
}