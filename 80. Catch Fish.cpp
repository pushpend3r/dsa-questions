// https://www.codingninjas.com/codestudio/problems/catch-fish_3583791

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<bool> &arr, int &netSize, int &n, int &k) {
  int sum = 0, index = 0;

  for (int i = 0; i < n; ++i) {
    if (i >= netSize)
      sum += arr.at(i) - arr.at(index++);
    else
      sum += arr.at(i);

    if (sum >= k) return true;
  }

  return false;
}

int minimumNet(int n, int k, vector<bool> fish) {
  int start = 0, end = n, mid, ans = -1;
  while (start <= end) {
    mid = start + (end - start) / 2;
    if (isPossible(fish, mid, n, k)) {
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
