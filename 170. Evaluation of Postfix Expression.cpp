// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

#include <bits/stdc++.h>

using namespace std;

int evaluatePostfix(string str) {
  stack<int> s;

  for (auto &ch : str) {
    if (ch >= '0' and ch <= '9') {
      s.push(ch - '0');
    } else {
      int op2 = s.top();
      s.pop();
      int op1 = s.top();
      s.pop();

      int ans = 0;

      switch (ch) {
        case '+':
          ans = op1 + op2;
          break;
        case '-':
          ans = op1 - op2;
          break;
        case '*':
          ans = op1 * op2;
          break;
        default:
          ans = op1 / op2;
          break;
      }

      s.push(ans);
    }
  }

  return s.top();
}