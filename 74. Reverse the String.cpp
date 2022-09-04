// https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927

#include <bits/stdc++.h>

using namespace std;

// ----- Approach 1 -------
void solve(string &str, int start, int end, string &ans) {
  // once we crossed paths
  if (start > end) return;

  // [...,str[start/end],....]
  if (start == end) {
    ans.push_back(str.at(start));
    return;
  }

  ans.push_back(str.at(end));
  solve(str, start + 1, end - 1, ans);
  ans.push_back(str.at(start));
}

string reverseString(string str) {
  string ans;
  solve(str, 0, str.size() - 1, ans);
  return ans;
}

// ---- Approach 2 -------
void solve(string &str, int start, int end) {
  if (start > end) return;
  swap(str.at(start++), str.at(end--));
  solve(str, start, end);
}

string reverseString(string str) {
  solve(str, 0, str.size() - 1);
  return str;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
