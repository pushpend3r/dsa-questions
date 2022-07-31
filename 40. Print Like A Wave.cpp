// https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268

#include <bits/stdc++.h>

using namespace std;

// Approach 1
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
  // true = asc, false = desc
  bool order = true;
  int j = 0;
  vector<int> ans;
  for (int i = 0; i < mCols; ++i) {
    while (j < nRows and j >= 0) {
      ans.push_back(arr.at(j).at(i));
      if (order)
        j++;
      else
        j--;
    }
    if (j == nRows)
      j--;
    else
      j++;
    order = !order;
  }

  return ans;
}

// Approach 2
vector<int> wavePrint2(vector<vector<int>> arr, int nRows, int mCols) {
  int atom, row = 0, col;
  vector<int> ans;
  for (col = 0; col < mCols; ++col) {
    atom = col % 2 ? -1 : 1;
    while (row >= 0 and row < nRows) {
      ans.push_back(arr.at(row).at(col));
      row += atom;
    }
    (row == nRows ? row-- : ++row);
  }

  return ans;
}

// Approach 3 (simple & sober)
vector<int> wavePrint3(vector<vector<int>> arr, int nRows, int mCols) {
  vector<int> ans;
  for (int col = 0; col < mCols; ++col)
    if (col & 1)
      for (int row = nRows - 1; row >= 0; --row) ans.push_back(arr[row][col]);
    else
      for (int row = 0; row < nRows; ++row) ans.push_back(arr[row][col]);
  return ans;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> arr = {{1, 2}, {3, 4}};
  for (const auto &i : wavePrint3(arr, 2, 2)) cout << i << " ";
  cout << endl;
  return 0;
}
