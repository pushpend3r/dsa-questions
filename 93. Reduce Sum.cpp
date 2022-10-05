// https://www.codingninjas.com/codestudio/problems/reduce-sum_3739112

#include <bits/stdc++.h>

using namespace std;

// Approach 1 (getting TLE for this..😔)
int solve(vector<vector<int>> &mat, int &n, int &m, int rowIndex,
          vector<int> colWiseSum, int ans) {
  if (rowIndex >= n) {
    for (int col = 0; col < m - 1; ++col)
      if (colWiseSum.at(m - 1) <= colWiseSum.at(col)) return ans;

    return INT_MAX;
  }

  int side1 = solve(mat, n, m, rowIndex + 1, colWiseSum, ans);

  for (int col = 0; col < m; ++col)
    colWiseSum.at(col) -= mat.at(rowIndex).at(col);

  int side2 = solve(mat, n, m, rowIndex + 1, colWiseSum, ans + 1);

  return min(side1, side2);
}

int countMinOp(int n, int m, vector<vector<int>> &mat) {
  vector<int> colWiseSum(m, 0);
  for (int col = 0; col < m; ++col)
    for (int row = 0; row < n; ++row) colWiseSum.at(col) += mat.at(row).at(col);

  return solve(mat, n, m, 0, colWiseSum, 0);
}

// Approach 2
/*
Suppose you have given 2 arrays A and B
A   B   C(diff)
3   2   1
2   5   -3
3   7   2
----------
8   9

On ideal state A's element must be greater and equal to B's element
In diff array,
non negative elements (including zero) = means we can definetly keep those rows
negative elements = they could be kept but need to check.
*/
int countMinOp(int n, int m, vector<vector<int>> &mat) {
  int ans = n;
  for (int col = 0; col < m - 1; ++col) {
    vector<int> diff;
    for (int row = 0; row < n; ++row)
      diff.push_back(mat.at(row).at(col) - mat.at(row).at(m - 1));
    // Sort the diff in decreasing order
    sort(diff.begin(), diff.end(), [&](int &a, int &b) { return a > b; });
    int sum = 0, k = 0;
    while (k < n and sum + diff.at(k) >= 0) {
      sum += diff.at(k);
      k++;
    }
    ans = min(ans, n - k);
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
