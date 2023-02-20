// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

#include <bits/stdc++.h>

using namespace std;

// using STL
string reverseWord(string str) {
  stack<char> s;
  for (auto &ch : str) s.push(ch);
  for (auto &ch : str) {
    ch = s.top();
    s.pop();
  }
  return str;
}
