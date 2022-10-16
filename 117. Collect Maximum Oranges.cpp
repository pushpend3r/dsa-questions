// https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-caratlane/problems/#

#include <bits/stdc++.h>

using namespace std;

class Solution {
  long long leftSide(vector<pair<int, long long>> &sums, int &n, int pos) {
    long long start = 0, end = n - 1, mid, ans = -1;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (sums[mid].first < pos) {
        ans = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    if (ans == -1) return 0;
    return sums[ans].second;
  }

  long long rightSide(vector<pair<int, long long>> &sums, int &n, int pos) {
    long long start = 0, end = n - 1, mid, ans = -1;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (sums[mid].first <= pos) {
        ans = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    if (ans == -1) return 0;
    return sums[ans].second;
  }

 public:
  vector<long long> collectMaximumOranges(int n, int q,
                                          vector<vector<int>> trees,
                                          vector<vector<int>> queries) {
    // sorted the tree by position
    sort(trees.begin(), trees.end(),
         [&](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    vector<pair<int, long long>> sums(n);
    sums[0].first = trees[0][0];
    sums[0].second = trees[0][1];

    // accummilated the sums
    for (int i = 1; i < n; ++i) {
      sums[i].first = trees[i][0];
      sums[i].second = trees[i][1] + sums[i - 1].second;
    }

    vector<long long> ans;

    for (int i = 0; i < q; ++i) {
      auto left = leftSide(sums, n, queries[i][0]);
      auto right = rightSide(sums, n, queries[i][1]);
      ans.push_back(right - left);
    }

    return ans;
  }
};
