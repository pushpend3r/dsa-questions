// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr, int start, int end) {
  if (start > end) return 0;

  int mid = start + (end - start) / 2, ans;

  if (arr[mid] < arr[mid + 1])
    return solve(arr, mid + 1, end);
  else {
    ans = mid;
    int tmp = solve(arr, start, mid - 1);
    if (tmp != 0) ans = tmp;
  }

  return ans;
}

int peakIndexInMountainArray(vector<int> &arr) {
  return solve(arr, 0, arr.size() - 1);
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {3, 5, 3, 2, 0};
  cout << peakIndexInMountainArray(arr) << endl;
  return 0;
}
