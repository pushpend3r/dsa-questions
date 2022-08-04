// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

#include <bits/stdc++.h>

using namespace std;

// Approach 1 - O(n * n)
int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
  int ans = 0, n = grid.size();
  vector<int> rowWiseMaximum(n), colWiseMaximum(n);
  /*
  // calulating row wise maximum
  for (const auto &i : grid)
    rowWiseMaximum.push_back(*max_element(i.begin(), i.end()));

  // calulating col wise maximum
  for (int col = 0; col < n; ++col) {
    int max = INT_MIN;
    for (int row = 0; row < n; ++row)
      if (grid[row][col] > max) max = grid[row][col];
    colWiseMaximum.push_back(max);
  }
  */

  for (int row = 0; row < n; ++row)
    for (int col = 0; col < n; ++col) {
      rowWiseMaximum[row] = max(rowWiseMaximum[row], grid[row][col]);
      colWiseMaximum[col] = max(colWiseMaximum[col], grid[row][col]);
    }

  for (int row = 0; row < n; ++row)
    for (int col = 0; col < n; ++col)
      ans += min(rowWiseMaximum[row], colWiseMaximum[col]) - grid[row][col];

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
