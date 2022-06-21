// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &arr, int k, int sum) {
  int currentPainter = 1;
  int curSum = 0;

  for (const int &n : arr) {
    if (n > sum) return false;

    if (curSum + n > sum) {
      currentPainter++;
      curSum = n;

      if (currentPainter > k) return false;
    } else
      curSum += n;
  }

  return true;
}

int findLargestMinDistance(vector<int> &arr, int k) {
  auto sum = accumulate(arr.begin(), arr.end(), 0);

  int start = 0, end = sum, mid, ans = -1;

  while (start <= end) {
    mid = start + (end - start) / 2;
    if (isPossible(arr, k, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
