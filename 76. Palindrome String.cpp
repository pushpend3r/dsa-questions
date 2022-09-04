// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#include <bits/stdc++.h>

using namespace std;

int solve(string &str, int start, int end) {
  if (start > end) return 1;
  if (str.at(start++) != str.at(end--)) return 0;
  return solve(str, start, end);
}

int isPalindrome(string S) { return solve(S, 0, S.size() - 1); }

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
