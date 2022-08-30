// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

#include <bits/stdc++.h>

using namespace std;

// Approach 1
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int n = rowSum.size(), m = colSum.size();
  vector<vector<int>> ans(n, vector<int>(m, 0));
  for (int row = 0; row < n; ++row)
    for (int col = 0; col < m; ++col) {
      ans.at(row).at(col) = min(rowSum.at(row), colSum.at(col));
      rowSum.at(row) -= ans.at(row).at(col);
      colSum.at(col) -= ans.at(row).at(col);
    }

  return ans;
}

// Approach 2
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int n = rowSum.size(), m = colSum.size(), i = 0, j = 0;
  vector<vector<int>> ans(n, vector<int>(m, 0));
  while (i < n and j < m) {
    ans.at(i).at(j) = min(rowSum.at(i), colSum.at(j));
    rowSum.at(i) -= ans.at(i).at(j);
    colSum.at(j) -= ans.at(i).at(j);
    if (rowSum.at(i) == 0) i++;
    if (colSum.at(j) == 0) j++;
  }
  return ans;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
