// https://practice.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int N, int X, int i = 0) {
  if (N == i) return -1;
  if (arr[i] == X) return i;
  return search(arr, N, X, ++i);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
