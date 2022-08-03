// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1

#include <bits/stdc++.h>
#define MAX 100

using namespace std;

// Naive Solution (still got accepted on GFG)
int kthSmallest(int mat[MAX][MAX], int n, int k) {
  vector<int> arr;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) arr.push_back(mat[i][j]);

  sort(arr.begin(), arr.end());
  return arr.at(k - 1);
}

int countElementThatAreLessOrEqual(int mat[MAX][MAX], int n, int num) {
  int ans = 0;
  for (int row = 0; row < n; ++row) {
    if (mat[row][0] > num) continue;
    if (mat[row][n - 1] <= num)
      ans += n;
    else {
      // it was right but because of MAX it was getting problem
      // ans += upper_bound(begin(mat[row]), end(mat[row]), num) -
      // begin(mat[row]);
      int start = 0, end = n - 1, mid;
      while (start < end) {
        mid = start + (end - start) / 2;
        if (mat[row][mid] > num)
          end = mid;
        else
          start = mid + 1;
      }
      ans += end;
    }
  }

  return ans;
}

// Approach 2 - Using binary search
int kthSmallest2(int mat[MAX][MAX], int n, int k) {
  int start = mat[0][0], end = mat[n - 1][n - 1], mid, count;
  while (start < end) {
    mid = start + (end - start) / 2;
    count = countElementThatAreLessOrEqual(mat, n, mid);
    if (count >= k)
      end = mid;
    else
      start = mid + 1;
  }
  return end;
}

int main(int argc, char const *argv[]) {
  int arr[MAX][MAX] = {{4, 9}, {6, 17}};
  cout << kthSmallest2(arr, 2, 3) << endl;
  return 0;
}
