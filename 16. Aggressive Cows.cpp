// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &arr, int k, int distance) {
  int cowPlaced = 1;
  int curPlacedIndex = 0;

  for (int i = 1; i < arr.size(); ++i) {
    if (abs(arr.at(i) - arr.at(curPlacedIndex)) >= distance) {
      cowPlaced++;
      if (cowPlaced == k) return true;
      curPlacedIndex = i;
    }
  }

  return false;
}

int aggressiveCows(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());
  int start = 0,
      end = *max_element(arr.begin(), arr.end()) -
            *min_element(arr.begin(), arr.end()),
      mid, ans = -1;

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
