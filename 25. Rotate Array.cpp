// https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>

using namespace std;

// My Approach
void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  k %= n;

  vector<int> temp(k);
  copy(nums.begin(), nums.begin() + k, temp.begin());

  for (int i = n - 1; i >= k; --i) {
    nums.at((i + k) % n) = nums.at(i);
  }

  for (int i = 0; i < k; ++i) nums.at((i + k) % n) = temp.at(i);
}

// Approach 2
void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  k %= n;

  for (int rotation = 1; rotation <= k; ++rotation) {
    int temp = nums.at(0);
    for (int i = n - 1; i > 0; --i) nums.at((i + 1) % n) = nums.at(i);
    nums.at(1 % n) = temp;
  }
}

// Approach 3
void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  k %= n;

  reverse(nums.begin(), nums.begin() + n - k);
  reverse(nums.begin() + n - k, nums.end());
  reverse(nums.begin(), nums.end());
}

int main(int argc, char const* argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  rotate(arr, 3);
  for (auto i : arr) cout << i << " ";
  cout << '\n';
  return 0;
}
