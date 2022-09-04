// https://www.codingninjas.com/codestudio/problems/check-palindrome_920555

#include <bits/stdc++.h>

using namespace std;

string binaryRepresentation(long long &N) {
  string ans;
  while (N) {
    if (N & 1)
      ans.push_back('1');
    else
      ans.push_back('0');
    N >>= 1;
  }
  return ans;
}

int solve(string &str, int start, int end) {
  if (start > end) return 1;
  if (str.at(start++) != str.at(end--)) return 0;
  return solve(str, start, end);
}

int isPalindrome(string S) { return solve(S, 0, S.size() - 1); }

bool checkPalindrome(long long N) {
  string binaryRep = binaryRepresentation(N);
  return isPalindrome(binaryRep);
}

int main(int argc, char const *argv[]) {
  checkPalindrome(10);
  return 0;
}
