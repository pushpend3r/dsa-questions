// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>

using namespace std;

// Binary Search Approach O(log(n * m))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int total_rows = matrix.size(), total_cols = matrix.at(0).size();

  int start = 0, end = total_rows * total_cols - 1, mid, element;

  while (start <= end) {
    mid = start + (end - start) / 2;

    element = matrix.at(mid / total_cols).at(mid % total_cols);

    if (element == target)
      return true;
    else if (element < target)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return false;
}

// Using Binary Search Tree Approach
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
