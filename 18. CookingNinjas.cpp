// https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &arr, int time, int m) {
  int sum = 0;
  int dishesCooked = 0;

  for (const auto &n : arr) {
    for (int i = 1; i <= m; ++i) {
      sum += n * i;
      if (sum <= time) dishesCooked++;
      if (dishesCooked == m) return true;
    }
    sum = 0;
  }

  return false;
}

int minCookTime(vector<int> &arr, int m) {
  int start = 0,
      end = ((m * (m + 1)) / 2) * *max_element(arr.begin(), arr.end()),
      ans = -1, mid;

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (isPossible(arr, mid, m)) {
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
