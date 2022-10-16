// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>

using namespace std;

// My Approach
int peakIndexInMountainArray(vector<int> &arr) {
  int start = 0, end = arr.size() - 1, mid = start + (end - start) / 2;
  bool greaterThanPrevious = false, greaterThanNext = false;

  while (start <= mid and mid <= end) {
    // Edge case when mid = 0 (start = 0, end = 1)
    if (mid == 0) mid++;

    greaterThanPrevious = arr.at(mid - 1) < arr.at(mid);
    greaterThanNext = arr.at(mid + 1) < arr.at(mid);

    if (greaterThanPrevious and greaterThanNext)
      return mid;
    else if (greaterThanPrevious and !greaterThanNext)
      start = mid + 1;
    else
      end = mid - 1;

    mid = start + (end - start) / 2;
  }

  return -1;
}

// Approach 2 - little better than mine
int peakIndexInMountainArray(vector<int> &arr) {
  // Why were we start from 0 and end = arr.length - 1? because we know our
  // answer will never be one of those.
  int start = 1, end = arr.size() - 2, mid = start + (end - start) / 2;
  bool greaterThanPrevious = false, greaterThanNext = false;

  while (start <= mid and mid <= end) {
    greaterThanPrevious = arr.at(mid - 1) < arr.at(mid);
    greaterThanNext = arr.at(mid + 1) < arr.at(mid);

    if (greaterThanPrevious and greaterThanNext)
      return mid;
    else if (greaterThanPrevious and !greaterThanNext)
      start = mid + 1;
    else
      end = mid - 1;

    mid = start + (end - start) / 2;
  }

  return -1;
}

// Approach 3 - love babber's
int peakIndexInMountainArray(vector<int> &arr) {
  int start = 1, end = arr.size() - 2, mid = start + (end - start) / 2;

  while (start < end) {
    if (arr.at(mid) < arr.at(mid + 1))
      start = mid + 1;
    else
      end = mid;

    mid = start + (end - start) / 2;
  }

  return start;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {3, 5, 3, 2, 0};
  cout << peakIndexInMountainArray(arr) << endl;
  return 0;
}
