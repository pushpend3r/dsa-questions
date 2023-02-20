// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

int findMinimumCost(string str) {
  // impossible
  if (str.length() % 2) return -1;

  stack<char> s;
  for (auto &ch : str) {
    if (ch == '{')
      s.push('{');
    else {
      if (s.empty() or s.top() == '}')
        s.push('}');
      else
        s.pop();
    }
  }

  int cost = 0;

  // if stack is not empty then some brackets are not balanced.
  while (!s.empty()) {
    if (s.top() == '{') cost++;
    s.pop();
    if (s.top() == '}') cost++;
    s.pop();
  }

  return cost;
}