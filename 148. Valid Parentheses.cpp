// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

char getOpeningChar(char ch) {
  if (ch == ')') return '(';
  if (ch == ']') return '[';
  if (ch == '}') return '{';
}

bool isValidParenthesis(string expression) {
  stack<char> s;

  for (auto &ch : expression) {
    if (ch == '{' or ch == '[' or ch == '(') {
      s.push(ch);
    } else {
      if (s.empty()) return false;
      auto top = s.top();
      s.pop();
      if (top != getOpeningChar(ch)) return false;
    }
  }

  return s.empty();
}