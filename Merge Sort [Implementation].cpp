// https://www.codingninjas.com/codestudio/problems/merge-sort_920442

#include <bits/stdc++.h>

using namespace std;

void merge2SortedArrays(vector<int> &arr, int &start, int &mid, int &end) {
  int pos1 = mid, pos2 = end;
  int pos = end - start;

  vector<int> ans(pos + 1);

  while (pos1 >= start and pos2 > mid) {
    if (arr.at(pos1) > arr.at(pos2))
      ans.at(pos) = arr.at(pos1--);
    else
      ans.at(pos) = arr.at(pos2--);
    pos--;
  }

  while (pos1 != start - 1) ans.at(pos--) = arr.at(pos1--);
  while (pos2 != mid) ans.at(pos--) = arr.at(pos2--);

  copy(ans.begin(), ans.end(), arr.begin() + start);
}

void solve(vector<int> &arr, int start, int end) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;
  solve(arr, start, mid);
  solve(arr, mid + 1, end);
  merge2SortedArrays(arr, start, mid, end);
}

void mergeSort(vector<int> &arr, int n) { solve(arr, 0, n - 1); }

// --

void insertionSort(vector<int> &arr, int &start, int &idx) {
  int i = idx - 1, temp = arr.at(idx);
  while (i >= start) {
    if (arr.at(i) >= temp)
      arr.at(i + 1) = arr.at(i);
    else
      break;
    i--;
  }
  arr.at(i + 1) = temp;
}

void solve2(vector<int> &arr, int start, int end) {
  // Base Case
  if (start >= end) return;

  int mid = start + (end - start) / 2;

  // Recursive Calls
  solve2(arr, start, mid);
  solve2(arr, mid + 1, end);

  // Merging
  int a1 = mid, a2 = end;
  while (a2 > mid) {
    if (arr.at(a2) < arr.at(a1)) {
      swap(arr.at(a2), arr.at(a1));
      insertionSort(arr, start, a1);
    }
    a2--;
  }
}

void mergeSort2(vector<int> &arr, int n) { solve2(arr, 0, n - 1); }

int main(int argc, char const *argv[]) {
  vector<int> arr = {2, 1, 1, 3, 1, 2, 1, 88};
  mergeSort(arr, arr.size());
  for (const auto &i : arr) cout << i << " ";
  cout << endl;
  return 0;
}
