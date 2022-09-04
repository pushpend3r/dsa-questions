// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1

#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int start, int end, int k) {
  if (start > end) return -1;

  int mid = start + (end - start) / 2;
  if (arr[mid] == k) return mid;

  return arr[mid] > k ? solve(arr, 0, mid - 1, k) : solve(arr, mid + 1, end, k);
}

int binarysearch(int arr[], int n, int k) { return solve(arr, 0, n - 1, k); }

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
