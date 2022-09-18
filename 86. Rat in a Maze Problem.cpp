// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>> &m, int &n, int row, int col, string path,
           vector<string> &ans) {
  // we don't want to go out of bound, do we?
  if (row < 0 or row == n or col < 0 or col == n) return;

  // we might been here or we shouldn't be on this point
  if (!m.at(row).at(col)) return;

  // we reached to the destination
  if (row == n - 1 and col == n - 1) {
    ans.push_back(path);
    return;
  }

  // marking so we don't come to this point again
  m.at(row).at(col) = 0;

  solve(m, n, row + 1, col, path + "D", ans);
  solve(m, n, row, col + 1, path + "R", ans);
  solve(m, n, row - 1, col, path + "U", ans);
  solve(m, n, row, col - 1, path + "L", ans);

  // reverting to back for other paths
  m.at(row).at(col) = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string> paths;
  solve(m, n, 0, 0, "", paths);
  return paths;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> matrix = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  for (const auto &i : findPath(matrix, matrix.size())) {
    cout << i << endl;
  }
  return 0;
}
