// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>

using namespace std;

// Approach 2 iterative
vector<string> mapping = {"abc", "def",  "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
  if (!digits.size()) return {};
  vector<string> ans = {""};
  for (const auto &i : digits) {
    vector<string> temp;
    for (const auto &j : mapping.at(i - '0' - 2)) {
      for (const auto &z : ans) temp.push_back(z + j);
    }
    ans.swap(temp);
  }
  return ans;
}

// Approach 1 using Recursion
void solve(string &str, int start, int end, string temp, vector<string> &ans) {
  if (start > end) {
    if (temp != "") ans.push_back(temp);
    return;
  }
  string &set = mapping.at(str.at(start) - '0' - 2);

  for (const auto &i : set) {
    temp.push_back(i);
    solve(str, start + 1, end, temp, ans);
    temp.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> ans;
  solve(digits, 0, digits.size() - 1, "", ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
