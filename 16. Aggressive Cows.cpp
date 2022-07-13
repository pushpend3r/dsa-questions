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

int aggressiveCows(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());
  int start = 0, end = arr.back() - arr.front(), mid, ans = -1;

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (isPossible(arr, k, mid)) {
      ans = mid;
      start = mid + 1;
    } else
      end = mid - 1;
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {0, 4, 3, 7, 10, 9};
  cout << aggressiveCows(arr, 3) << endl;
  return 0;
}
