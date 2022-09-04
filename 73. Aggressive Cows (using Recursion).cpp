// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &arr, int k, int distance) {
  int cowPlaced = 1;
  int curPlacedIndex = arr.size() - 1;

  for (int i = curPlacedIndex - 1; i >= 0; --i) {
    if (arr.at(curPlacedIndex) - arr.at(i) >= distance) {
      cowPlaced++;
      if (cowPlaced == k) return true;
      curPlacedIndex = i;
    }
  }

  return false;
}

int solve(vector<int> &arr, int start, int end, int k) {
  if (start > end) return -1;
  int mid = start + (end - start) / 2, ans, tmp;
  if (isPossible(arr, k, mid)) {
    ans = mid;
    tmp = solve(arr, mid + 1, end, k);
    if (tmp != -1) ans = tmp;
  } else
    return solve(arr, start, mid - 1, k);
  return ans;
}

int aggressiveCows(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());
  return solve(arr, 0, arr.back() - arr.front(), k);
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {4, 2, 1, 3, 6};
  cout << aggressiveCows(arr, 2) << endl;
  return 0;
}
