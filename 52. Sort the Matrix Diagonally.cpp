// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include <bits/stdc++.h>

using namespace std;

/* Approach 1 */
void bubbleSort(vector<vector<int>>& mat, int row, int col) {
  int n = min(mat.size() - row, mat.at(0).size() - col);
  for (int round = 1; round < n; ++round) {
    bool isSwapped = false;
    for (int i = 0; i < n - round; ++i) {
      if (mat.at(row + i).at(col + i) > mat.at(row + i + 1).at(col + i + 1)) {
        isSwapped = true;
        swap(mat.at(row + i).at(col + i), mat.at(row + i + 1).at(col + i + 1));
      }
    }
    if (!isSwapped) break;
  }
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
  int n = mat.size(), m = mat.at(0).size();
  for (int col = 0; col < m; ++col) bubbleSort(mat, 0, col);
  for (int row = 0; row < n; ++row) bubbleSort(mat, row, 0);
  return mat;
}

/* Appoach 2 */
void sortDiagonal(vector<vector<int>>& mat, int i, int j, int& n, int& m) {
  vector<int> values;
  while (i < n && j < m) values.push_back(mat.at(i++).at(j++));
  sort(values.begin(), values.end());
  while (i and j) {
    mat[--i][--j] = values.back();
    values.pop_back();
  }
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
  int n = mat.size(), m = mat.at(0).size();
  for (int col = 0; col < m; ++col) sortDiagonal(mat, 0, col, n, m);
  for (int row = 0; row < n; ++row) sortDiagonal(mat, row, 0, n, m);
  return mat;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
  for (const auto& i : diagonalSort2(mat)) {
    for (const auto& j : i) cout << j << " ";
    cout << endl;
  }
  return 0;
}
