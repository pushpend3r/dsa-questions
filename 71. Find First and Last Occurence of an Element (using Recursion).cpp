// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int k, int start, int end, int mode = 0) {
  if (start > end) return -1;
  int mid = start + (end - start) / 2;
  int ans;
  if (arr[mid] == k) {
    ans = mid;
    if (mode == 1) {
      int temp = binarySearch(arr, k, start, mid - 1, mode);
      if (temp != -1) ans = temp;
    } else if (mode == 2) {
      int temp = binarySearch(arr, k, mid + 1, end, mode);
      if (temp != -1) ans = temp;
    } else
      return mid;
  } else if (arr[mid] < k)
    return binarySearch(arr, k, mid + 1, end, mode);
  else
    return binarySearch(arr, k, start, mid - 1, mode);

  return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
  int size = n;
  int leftMostIndex = -1, rightMostIndex = -1;

  int index = binarySearch(arr, k, 0, size - 1);

  if (index != -1) {
    leftMostIndex = binarySearch(arr, k, 0, index - 1, 1);
    rightMostIndex = binarySearch(arr, k, index + 1, size - 1, 2);

    if (leftMostIndex == -1) leftMostIndex = index;
    if (rightMostIndex == -1) rightMostIndex = index;
  }

  return make_pair(leftMostIndex, rightMostIndex);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
