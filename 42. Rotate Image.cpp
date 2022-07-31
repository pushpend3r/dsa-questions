// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>

using namespace std;

// Approach 1
void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size(), i = 0, j;
  for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j) swap(matrix.at(i).at(j), matrix.at(j).at(i));
  }
  for (auto& i : matrix) reverse(i.begin(), i.end());
}

// Approach 2
// https://leetcode.com/problems/rotate-image/discuss/19002/4ms-few-lines-C%2B%2B-code-Rotate-Image-90-degree-for-O(1)-space
void rotate(vector<vector<int>>& matrix) {
  int i = 0, j = matrix.size() - 1, index;
  while (i < j) {
    // Rotating Ring by Ring
    for (index = 0; index < j - i; ++index) {
      swap(matrix.at(i).at(i + index), matrix.at(i + index).at(j));
      swap(matrix.at(i).at(i + index), matrix.at(j).at(j - index));
      swap(matrix.at(i).at(i + index), matrix.at(j - index).at(i));
    }
    ++i, --j;
  }
}

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
