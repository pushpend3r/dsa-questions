// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <bits/stdc++.h>

using namespace std;

// Approach 1
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
  int ans = -1, count = 0, currentRowCount = 0;
  for (int i = 0; i < n; ++i) {
    currentRowCount =
        arr.at(i).end() - upper_bound(arr.at(i).begin(), arr.at(i).end(), 0);
    if (currentRowCount > count) {
      count = currentRowCount;
      ans = i;
    }
  }

  return ans;
}

// Approach 2 -> O (n * m)
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
  for (int col = 0; col < m; ++col)
    for (int row = 0; row < n; row++)
      if (arr.at(row).at(col)) return row;

  return -1;
}

// Approach 3 -> O(n + m)
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
  int col = m - 1, ans = -1;
  bool flag = 0;
  for (int row = 0; row < n; ++row) {
    while (col >= 0 and arr.at(row).at(col)) {
      col--;
      flag = 1;
    }
    if (flag) ans = row;
    flag = 0;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
