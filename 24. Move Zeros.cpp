// https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>

using namespace std;

// My Approach
void moveZeroes(vector<int>& nums) {
  int n = nums.size();
  int start = 0, end = 1;
  while (end < n) {
    while (start < n and nums.at(start) != 0) start++;
    end = start + 1;
    while (end < n and nums.at(end) == 0) end++;
    if (end < n) swap(nums.at(start), nums.at(end));
  }
}

// Approach 2
void moveZeroes(vector<int>& nums) {
  int n = nums.size();
  for (int i = 0, cur = 0; cur < n; cur++)
    if (nums[cur]) swap(nums[i++], nums[cur]);
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
