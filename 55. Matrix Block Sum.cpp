// https://leetcode.com/problems/matrix-block-sum/

#include <bits/stdc++.h>

using namespace std;

/* -- Approach 1 -- */

int getValue(const vector<vector<int>> &mat, int row, int col, const int &n,
             const int &m, const int &k) {
  // BR -> Bottom Right, TR -> Top Right, BL -> Bottom Left, TL -> Top Left

  auto BRIdx = make_pair(row + k, col + k),
       TLIdx = make_pair(row - k - 1, col - k - 1),
       TRIdx = make_pair(row - k - 1, col + k),
       BLIdx = make_pair(row + k, col - k - 1);

  int BR, TR, BL, TL;

  BR = mat.at(BRIdx.first >= n ? n - 1 : BRIdx.first)
           .at(BRIdx.second >= m ? m - 1 : BRIdx.second);

  TL = TLIdx.first < 0 or TLIdx.second < 0
           ? 0
           : mat.at(TLIdx.first).at(TLIdx.second);

  TR = TRIdx.first < 0
           ? 0
           : mat.at(TRIdx.first).at(TRIdx.second >= m ? m - 1 : TRIdx.second);

  BL = BLIdx.second < 0
           ? 0
           : mat.at(BLIdx.first >= n ? n - 1 : BLIdx.first).at(BLIdx.second);

  return BR - TR - BL + TL;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
  int n = mat.size(), m = mat.at(0).size();
  vector<vector<int>> ans(n, vector<int>(m, 0));

  // Row Wise Sum
  for (int row = 0; row < n; ++row)
    for (int col = 1; col < m; ++col)
      mat.at(row).at(col) += mat.at(row).at(col - 1);

  // Column Wise Sum
  for (int row = 1; row < n; ++row)
    for (int col = 0; col < m; ++col)
      mat.at(row).at(col) += mat.at(row - 1).at(col);

  for (int row = 0; row < n; ++row)
    for (int col = 0; col < m; ++col)
      ans.at(row).at(col) = getValue(mat, row, col, n, m, k);

  return ans;
}

/* Approach 2 */
// https://leetcode.com/problems/matrix-block-sum/discuss/477041/Java-Prefix-sum-with-Picture-explain-Clean-code-O(m*n)/739379
vector<vector<int>> matrixBlockSum2(vector<vector<int>> &mat, int k) {
  int n = mat.size(), m = mat.at(0).size();
  vector<vector<int>> sums(n + 1, vector<int>(m + 1, 0));

  for (int row = 1; row <= n; ++row)
    for (int col = 1; col <= m; ++col)
      sums.at(row).at(col) =
          sums.at(row - 1).at(col) + sums.at(row).at(col - 1) -
          sums.at(row - 1).at(
              col - 1) /* we need to subtract this part because it has been
                          added 2 twice by row, col - 1 and row - 1, col */
          + mat.at(row - 1).at(col - 1);

  for (int row = 1; row <= n; ++row) {
    for (int col = 1; col <= m; ++col) {
      int r1 = min(n, row + k);
      int c1 = min(m, col + k);
      int r2 = max(1, row - k);
      int c2 = max(1, col - k);
      mat.at(row - 1).at(col - 1) = sums.at(r1).at(c1)        // Bottom Right
                                    - sums.at(r2 - 1).at(c1)  // Top Right
                                    + sums.at(r2 - 1).at(c2 - 1)  // Top Left
                                    - sums.at(r1).at(c2 - 1)      // Bottom Left
          ;
    }
  }

  return mat;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (const auto &i : matrixBlockSum2(mat, 1)) {
    for (const auto &j : i) cout << j << " ";
    cout << endl;
  }
  return 0;
}
