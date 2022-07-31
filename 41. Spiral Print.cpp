// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int total_Rows = matrix.size();
  int total_Cols = matrix.at(0).size();
  int index;

  int startingRow = 0, endingRow = total_Rows - 1;
  int startingCol = 0, endingCol = total_Cols - 1;

  int count = 0, total = total_Rows * total_Cols;

  vector<int> ans;

  while (count < total) {
    for (index = startingCol; count < total and index <= endingCol; ++index) {
      ans.push_back(matrix.at(startingRow).at(index));
      count++;
    }
    startingRow++;

    for (index = startingRow; count < total and index <= endingRow; ++index) {
      ans.push_back(matrix.at(index).at(endingCol));
      count++;
    }
    endingCol--;

    for (index = endingCol; count < total and index >= startingCol; --index) {
      ans.push_back(matrix.at(endingRow).at(index));
      count++;
    }
    endingRow--;

    for (index = endingRow; count < total and index >= startingRow; --index) {
      ans.push_back(matrix.at(index).at(startingCol));
      count++;
    }
    startingCol++;
  }

  return ans;
}

// Approach 2
// https://leetcode.com/problems/spiral-matrix/discuss/20573/A-concise-C++-implementation-based-on-Directions
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int row = 0, col = -1, index = 0 /* current direction's index we are on */;

  vector<int> ans, steps = {(int)matrix[0].size() /* total columns */,
                            (int)matrix.size() - 1 /* total rows - 1 */};
  // On above you can see that we use {total columns, total rows - 1}
  // Reason we already on row = 0

  // [1] = left to right
  // [2] = top to bottom
  // [3] = right to left
  // [4] = bottom to top

  while (steps.at(index % 2)) {
    for (int i = 0; i < steps.at(index % 2); ++i) {
      row += directions.at(index)[0];
      col += directions.at(index)[1];
      ans.push_back(matrix.at(row).at(col));
    }
    steps.at(index % 2)--;
    // so that we can traverse directions in loop like 0,1,2,3,0,1,2,3....
    index = (index + 1) % 4;
  }

  return ans;
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
