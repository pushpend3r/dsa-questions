// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <bits/stdc++.h>

using namespace std;

// Naive Approach O(nlogn) where n = r * c
int median(vector<vector<int>> &matrix, int r, int c) {
  vector<int> arr;
  for (const auto &row : matrix)
    for (const auto &element : row) arr.push_back(element);

  sort(arr.begin(), arr.end());
  return arr.at((r * c) / 2);
}

// Binary Search Approach O(32 * r * log(c))
int median(vector<vector<int>> &matrix, int r, int c) {
  int min = INT_MAX, max = INT_MIN, mid, requiredCount = (r * c) / 2,
      currentCount = 0;

  for (int i = 0; i < r; ++i) {
    min = std::min(min, matrix.at(i).at(0));
    max = std::max(max, matrix.at(i).at(c - 1));
  }

  while (min < max) {
    mid = min + (max - min) / 2;

    for (const auto &row : matrix)
      currentCount += upper_bound(row.begin(), row.end(), mid) - row.begin();

    // add 1 because mid is also included in the count as we are getting upper
    // bound above
    if (currentCount < requiredCount + 1)
      min = mid + 1; /* We are for sure that ans will be greater than min */
    else
      max = mid;

    currentCount = 0;
  }

  // could return max it doesn't matter
  return min;

  /* Note - Upper Bound Time Complexity is logn where n = array/vector length, I
   * think it uses Binary Search internally */
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
