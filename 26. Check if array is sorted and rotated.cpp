// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <bits/stdc++.h>

using namespace std;

// My Approach
bool check(vector<int>& nums) {
  bool downFall = false;

  for (int i = 1; i < nums.size(); ++i) {
    if (nums.at(i) < nums.at(i - 1)) {
      if (downFall) return false;
      downFall = true;
    }

    if (downFall and nums.at(i) > nums.at(0)) return false;
  }

  return true;
}

// Approach 2
bool check(vector<int>& nums) {
  int downFallCount = 0;
  int n = nums.size();

  for (int i = 0; i < n; ++i) {
    if (nums.at(i) > nums.at((i + 1) % n)) downFallCount++;
    if (downFallCount == 2) return false;
  }

  return true;
}

int main(int argc, char const* argv[]) {
  vector<int> arr = {1, 2, 3};
  cout << boolalpha << check(arr) << endl;
  return 0;
}
