// https://practice.geeksforgeeks.org/contest/weekly-interview-series-71/problems#

#include <bits/stdc++.h>

using namespace std;

vector<long long> smallerSum(int n, vector<int> &arr) {
  vector<vector<long long>> mat(n, vector<long long>(4, 0));
  for (int i = 0; i < n; ++i) {
    mat[i][0] = i;
    mat[i][1] = arr[i];
  }

  // sort by value
  sort(mat.begin(), mat.end(),
       [&](vector<long long> &a, vector<long long> &b) { return a[1] < b[1]; });

  mat[0][2] = mat[0][1];
  for (int i = 1; i < n; ++i) {
    mat[i][2] = mat[i][1] + mat[i - 1][2];
  }

  mat[0][3] = 0;

  for (int i = 1; i < n; ++i) {
    if (mat[i][1] == mat[i - 1][1]) {
      mat[i][3] = mat[i - 1][3];
    } else {
      mat[i][3] = mat[i - 1][2];
    }
  }

  // sort by index
  sort(mat.begin(), mat.end(),
       [&](vector<long long> &a, vector<long long> &b) { return a[0] < b[0]; });

  vector<long long> ans(n);

  for (int i = 0; i < n; ++i) ans[i] = mat[i][3];

  return ans;
}

// Approach 2
vector<long long> smallerSum(int n, vector<int> &arr) {
  auto temp = arr;
  vector<long long> prefixSum(n);

  sort(temp.begin(), temp.end());

  prefixSum[0] = temp[0];

  for (int i = 1; i < n; ++i) prefixSum[i] = temp[i] + prefixSum[i - 1];

  vector<long long> ans;

  for (int i = 0; i < n; ++i) {
    int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    if (index == 0) {
      ans.push_back(0);
    } else {
      index--;
      ans.push_back(prefixSum[index]);
    }
  }

  return ans;
}