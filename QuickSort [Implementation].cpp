// https://www.codingninjas.com/codestudio/problems/quick-sort_983625

#include <bits/stdc++.h>

using namespace std;

// Approach 2
int partition(vector<int> &arr, int l, int h) {
  int x = arr[h];
  int i = (l - 1);

  for (int j = l; j <= h - 1; j++) {
    if (arr[j] <= x) {
      i++;
      swap(arr.at(i), arr.at(j));
    }
  }
  swap(arr.at(i + 1), arr.at(h));
  return (i + 1);
}

void solve(vector<int> &arr, int start, int end) {
  if (start >= end) return;

  // pivot's right position
  int p = partition(arr, start, end);

  // recursive calls
  solve(arr, start, p - 1);
  solve(arr, p + 1, end);
}

// Approach 1
void solve(vector<int> &arr, int start, int end) {
  if (start >= end) return;

  // pivot's right position
  int p = count_if(arr.begin() + start, arr.begin() + end,
                   [&](int &i) { return i < arr.at(end); }) +
          start;

  // putting pivot to it's right position
  swap(arr.at(p), arr.at(end));

  // making pivot's left side only small elements
  // and right side only equals and bigger elements
  int i = start, j = end;
  while (i < p and j > p) {
    while (arr.at(i) < arr.at(p)) i++;

    // we don't want to overrun the p as well
    while (j > p and arr.at(j) >= arr.at(p)) j--;

    swap(arr.at(i), arr.at(j));
    i++;
    j--;
  }

  // recursive calls
  solve(arr, start, p - 1);
  solve(arr, p + 1, end);
}

vector<int> quickSort(vector<int> arr) {
  solve(arr, 0, arr.size() - 1);
  return arr;
}

int main(int argc, char const *argv[]) {
  for (const auto &i : quickSort({5, 3, 2, 6, 4})) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
