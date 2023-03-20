// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

#include <bits/stdc++.h>

using namespace std;

/*
Problem is to merge intervals that are **not** mutually exclusive.
[1, 4] and [3, 5] = not mutually exclusive -> [1,5]
[1, 4] and [5, 7] = mutually exclusive -> no change
[1, 4] and [4, 5] = not mutually exclusive -> [1,5]
*/

// approach 1 - O(n^2) [TC]
vector<vector<int>> overlappedInterval(vector<vector<int>> &arr) {
  // sort the intervals
  sort(arr.begin(), arr.end(),
       [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

  int size = arr.size();

  vector<vector<int>> ans;
  vector<bool> mergedIntervals(size, false);

  for (int i = 0; i < size; ++i) {
    if (mergedIntervals.at(i) == true) continue;

    auto &start = arr.at(i).at(0);
    auto &end = arr.at(i).at(1);

    for (int j = i + 1; j < size; ++j) {
      if (mergedIntervals.at(j) == true) continue;

      auto &current_start = arr.at(j).at(0);
      auto &current_end = arr.at(j).at(1);

      if (i == j or !(start <= current_start and current_start <= end))
        continue;

      end = max(end, current_end);
      mergedIntervals.at(j) = true;
    }
  }

  for (int i = 0; i < size; ++i) {
    if (mergedIntervals.at(i) == true) continue;
    ans.push_back(arr.at(i));
  }

  return ans;
}

// approach 2 - O(n*logn) [TC]
vector<vector<int>> overlappedInterval(vector<vector<int>> &arr) {
  // sort the intervals
  sort(arr.begin(), arr.end(),
       [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

  int size = arr.size();

  vector<vector<int>> ans;
  ans.push_back(arr[0]);

  for (int i = 1; i < size; ++i) {
    auto &top_start = ans.back().at(0);
    auto &top_end = ans.back().at(1);

    auto &current_start = arr.at(i).at(0);
    auto &current_end = arr.at(i).at(1);

    if (current_start <= top_end) {
      top_end = max(top_end, current_end);
    } else {
      ans.push_back(arr[i]);
    }
  }

  return ans;
}

// approach 3 - O(n*logn) [TC] **BEST**
vector<vector<int>> overlappedInterval(vector<vector<int>> &arr) {
  // sort the intervals
  sort(arr.begin(), arr.end(),
       [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

  int size = arr.size();

  int index = 0;

  for (int i = 1; i < size; ++i) {
    auto &end = arr.at(index).at(1);

    auto &current_start = arr.at(i).at(0);
    auto &current_end = arr.at(i).at(1);

    // do the merging
    if (current_start <= end) {
      end = max(end, current_end);
    } else {
      index++;
      arr.at(index) = arr.at(i);
    }
  }

  // remove unnesscary items
  arr.resize(index + 1);

  return arr;
}