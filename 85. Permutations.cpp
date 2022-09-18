// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int index, vector<vector<int>>& ans) {
  if (index >= arr.size()) {
    ans.push_back(arr);
    return;
  }
  for (int j = index; j < arr.size(); ++j) {
    swap(arr.at(j), arr.at(index));
    solve(arr, index + 1, ans);
    swap(arr.at(j), arr.at(index));
  }
}
vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> ans;
  solve(nums, 0, ans);
  return ans;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
