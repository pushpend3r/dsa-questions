// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

// Using Binary Search Tree Approach O(m + n)
// https://leetcode.com/problems/search-a-2d-matrix/discuss/1895837/C%2B%2B-BINARY-SEARCH-TREE-(**)-Explained-with-IMG
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int total_rows = matrix.size(), total_cols = matrix.at(0).size();
  int row = 0, col = total_cols - 1;

  while (row < total_rows and col > -1) {
    if (matrix.at(row).at(col) == target) return true;
    (matrix.at(row).at(col) < target ? row++ : col--);
  }

  return false;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
