// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include <bits/stdc++.h>

using namespace std;

/*
wiki - https://en.wikipedia.org/wiki/Shunting_yard_algorithm
*/

bool isOperator(char ch) {
  return ch == '+' or ch == '-' or ch == '^' or ch == '*' or ch == '/';
}

// higher the value means higher precedence
int precedence(char ch) {
  if (ch == '^') return 4;
  if (ch == '*' or ch == '/') return 3;
  if (ch == '+' or ch == '-') return 2;
  return 1;
}

string infixToPostfix(string s) {
  string ans;
  stack<char> stk;

  for (auto &ch : s) {
    // goto next iteration
    if (ch == ' ') continue;

    if (ch == ')') {
      while (stk.top() != '(') {
        ans.push_back(stk.top());
        stk.pop();
      }
      stk.pop();
    } else if (ch == '(' or ch == '^') {
      stk.push(ch);
    } else if (isOperator(ch) == true) {
      while (!stk.empty() and precedence(stk.top()) >= precedence(ch)) {
        ans.push_back(stk.top());
        stk.pop();
      }
      stk.push(ch);
    } else {
      ans.push_back(ch);
    }
  }

  while (!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  cout << infixToPostfix("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3") << endl;
  return 0;
}
