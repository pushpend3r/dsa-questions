// https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr, int start, int end) {
  if (start > end) return;
  int temp = arr.at(start), i = start - 1;
  while (i >= 0) {
    if (arr.at(i) > temp)
      arr.at(i + 1) = arr.at(i);
    else
      break;
    i--;
  }
  swap(arr.at(i + 1), temp);
  solve(arr, start + 1, end);
}

void insertionSort(int n, vector<int> &arr) { solve(arr, 1, n - 1); }

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
