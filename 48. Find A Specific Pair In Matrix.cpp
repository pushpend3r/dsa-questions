// https://www.codingninjas.com/codestudio/problems/find-a-specific-pair-in-the-matrix_1115467

#include <bits/stdc++.h>

using namespace std;

// getting TLE on this
int findMaxValue(vector<vector<int>>& mat, int n) {
  int ans = INT_MIN;
  for (int row = 0; row < n; ++row)
    for (int col = 0; col < n; ++col)
      for (int i = row + 1; i < n; ++i)
        for (int j = col + 1; j < n; ++j)
          ans = max(ans, mat.at(i).at(j) - mat.at(row).at(col));

  return ans;
}

// Approach 2
int findMaxValue2(vector<vector<int>>& mat, int n) {
  int ans = INT_MIN;
  int maxes[n - 1][n - 1], rightMostMax, bottomMostMax;

  for (int row = n - 1; row > 0; row--)
    for (int col = n - 1; col > 0; col--) {
      rightMostMax = col + 1 == n ? INT_MIN : maxes[row - 1][col];
      bottomMostMax = row + 1 == n ? INT_MIN : maxes[row][col - 1];
      maxes[row - 1][col - 1] =
          max({mat[row][col], rightMostMax, bottomMostMax});
    }

  for (int row = 0; row < n - 1; row++)
    for (int col = 0; col < n - 1; col++)
      ans = max(ans, maxes[row][col] - mat[row][col]);

  return ans;
}

// Approach 3
int findMaxValue3(vector<vector<int>>& mat, int n) {
  int ans = INT_MIN;
  int maxes[n - 1][n - 1], rightMostMax, bottomMostMax;

  for (int row = n - 1; row > 0; row--)
    for (int col = n - 1; col > 0; col--) {
      rightMostMax = col + 1 == n ? INT_MIN : maxes[row - 1][col];
      bottomMostMax = row + 1 == n ? INT_MIN : maxes[row][col - 1];
      maxes[row - 1][col - 1] =
          max({mat[row][col], rightMostMax, bottomMostMax});
      ans = max(ans, maxes[row - 1][col - 1] - mat[row - 1][col - 1]);
    }

  return ans;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> mat = {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}};
  cout << findMaxValue3(mat, 3) << endl;
  return 0;
}
