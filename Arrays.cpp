#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int row, col;
  cin >> row >> col;
  int arr[row][col];

  // input
  for (int i = 0; i < row; ++i)
    for (int j = 0; j < col; ++j) cin >> arr[i][j];

  int sum = 0;
  int ans[row];
  for (int i = 0; i < row; ++i) {
    sum = 0;
    for (int j = 0; j < col; ++j) sum += arr[i][j];
    ans[i] = sum;
  }

  for (const auto &i : ans) cout << i << ' ';
  cout << endl;
}
