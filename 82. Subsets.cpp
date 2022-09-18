// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>

using namespace std;

// Approach 2 (Bit Masking)
// -- https://www.youtube.com/watch?v=mqCdA8mcJeo
// -- https://www.youtube.com/watch?v=wpWGDHmpbgA
vector<int> solve(int subset, vector<int>& arr) {
  vector<int> ans;
  int i = 0;
  while (subset) {
    if (subset & 1) ans.push_back(arr.at(i));
    subset >>= 1;
    i++;
  }
  return ans;
}
vector<vector<int>> subsets(vector<int>& nums) {
  int totalSubsets = pow(2, nums.size());
  vector<vector<int>> ans;
  while (totalSubsets--) {
    ans.push_back(solve(totalSubsets, nums));
  }
  return ans;
}

// Approach 1

void solve(vector<int>& arr, int start, int end, vector<int> temp,
           vector<vector<int>>& ans) {
  if (start > end) {
    ans.push_back(temp);
    return;
  }

  solve(arr, start + 1, end, temp, ans);
  temp.push_back(arr.at(start));
  solve(arr, start + 1, end, temp, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> ans;
  solve(nums, 0, nums.size() - 1, {}, ans);
  return ans;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
