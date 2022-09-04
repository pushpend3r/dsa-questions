// https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

#include <bits/stdc++.h>

using namespace std;

// ----- Approach 1 ------------

bool solve(int arr[], int i, int n) {
  if (i == n - 1) return true;
  return arr[i] < arr[i + 1] and solve(arr, i + 1, n);
}

bool arraySortedOrNot(int arr[], int n) { return solve(arr, 0, n); }

// --------------------------------

// ----- Approach 2 --------------

bool arraySortedOrNot(int arr[], int n) {
  if (n < 2) return true;
  if (arr[0] > arr[1]) return false;
  return arraySortedOrNot(arr + 1, --n);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
