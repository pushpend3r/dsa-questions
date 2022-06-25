// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-l/problems/14463

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<vector<int>> &arr, int B, int X) {
  long long sum = 0;
  for (const auto &n : arr) {
    for (int i = 1; i < n.size(); ++i)
      if (n.at(i) <= X) sum += n.at(i);

    if (sum > B) return false;
  }

  return true;
}

int findMaxX(int n, vector<vector<int>> &arr, int B) {
  int start = 0, last = INT_MIN, mid, ans;

  for (const auto &element : arr)
    last = max(last, *max_element(element.begin() + 1, element.end()));

  if (start > B)
    return B;
  else if (last > B)
    last = B;

  while (start <= last) {
    mid = start + (last - start) / 2;
    if (isPossible(arr, B, mid)) {
      ans = mid;
      start = mid + 1;
    } else {
      last = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> arr = {{3, 1, 2, 3}, {3, 4, 2, 3}, {3, 1, 10, 2}};
  findMaxX(3, arr, 10);
  return 0;
}
