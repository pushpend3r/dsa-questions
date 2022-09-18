// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087

#include <bits/stdc++.h>

using namespace std;

// -- Approach 2 (Bit Masking)
// -- https://www.youtube.com/watch?v=mqCdA8mcJeo
// -- https://www.youtube.com/watch?v=wpWGDHmpbgA
string solve(int n, string &str) {
  string ans = "";
  int i = 0;
  while (n) {
    if (n & 1) ans.push_back(str.at(i));
    n >>= 1;
    i++;
  }
  return ans;
}
vector<string> subsequences(string str) {
  int totalSubsets = pow(2, str.size());
  vector<string> ans;
  while (totalSubsets--) ans.push_back(solve(totalSubsets, str));
  // removing the empty one
  ans.pop_back();
  return ans;
}

// -- Approach 1
void solve(string &str, int start, int end, string tempStr,
           vector<string> &ans) {
  if (start > end) {
    if (tempStr != "") {
      ans.push_back(tempStr);
    }
    return;
  }

  solve(str, start + 1, end, tempStr, ans);
  tempStr.push_back(str.at(start));
  solve(str, start + 1, end, tempStr, ans);
}

vector<string> subsequences(string str) {
  vector<string> ans;
  solve(str, 0, str.size() - 1, "", ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
