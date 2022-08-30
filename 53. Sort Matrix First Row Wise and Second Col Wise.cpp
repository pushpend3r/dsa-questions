// https://www.geeksforgeeks.org/sort-matrix-row-wise-column-wise/

#include <bits/stdc++.h>

using namespace std;

void sortByRow(vector<vector<int>>& ans, int& n, int& m) {
  for (int row = 0; row < n; ++row)
    sort(ans.at(row).begin(), ans.at(row).begin() + m);
}

void transpose(vector<vector<int>>& ans, int& n, int& m) {
  for (int row = 0; row < max(n, m); ++row)
    for (int col = row + 1; col < max(n, m); ++col)
      swap(ans.at(row).at(col), ans.at(col).at(row));

  swap(n, m);
}

vector<vector<int>> sortRowAndColWise(vector<vector<int>>& mat) {
  int n = mat.size(), m = mat.at(0).size();
  vector<vector<int>> ans(max(n, m), vector<int>(max(n, m), 0));

  // copying to ans
  for (int row = 0; row < n; ++row)
    for (int col = 0; col < m; ++col) ans.at(row).at(col) = mat.at(row).at(col);

  // Row Wise Sort
  sortByRow(ans, n, m);

  // Transpose it
  transpose(ans, n, m);

  // Row Wise Sort
  sortByRow(ans, n, m);

  // Transpose it
  transpose(ans, n, m);

  for (auto& i : ans) i.resize(m);
  ans.resize(n);

  return ans;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
