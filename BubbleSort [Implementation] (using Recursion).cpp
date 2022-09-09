// https://www.codingninjas.com/codestudio/problems/bubble-sort_980524

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& arr, int start, int end) {
  // base case
  if (start >= end) return;

  for (int i = start; i < end; ++i)
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);

  // manage rounds
  solve(arr, start, end - 1);
}

void bubbleSort(vector<int>& arr, int n) { solve(arr, 0, arr.size() - 1); }

int main(int argc, char const* argv[]) {
  vector<int> arr = {10, 9, 8, 7, 6};
  bubbleSort(arr, arr.size());
  for (const auto& i : arr) cout << i << " ";
  cout << endl;
  return 0;
}
