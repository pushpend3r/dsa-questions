// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
#define ul unsigned int
using namespace std;

bool isPossible(vector<ul> &arr, ul height, ul m) {
  ul sum = 0;

  for (const ul &n : arr) {
    if (n > height) sum += (n - height);
    if (sum >= m) return true;
  }

  return false;
}

ul findMaximumHeight(vector<ul> &arr, int m) {
  ul start = 0, end = *max_element(arr.begin(), arr.end()), mid, ans = -1;

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (isPossible(arr, mid, m)) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  ul n, m;
  cin >> n >> m;
  vector<ul> arr(n);
  for (ul &i : arr) cin >> i;
  cout << findMaximumHeight(arr, m);
  return 0;
}
