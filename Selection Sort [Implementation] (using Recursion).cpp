// https://www.codingninjas.com/codestudio/problems/selection-sort_981162

#include <bits/stdc++.h>

using namespace std;

int selectionSort(vector<int> &arr, int n) {
  if (n == 1) return;
  int posToReplaceWith = n - 1;
  for (int i = 0; i < n - 1; i++)
    if (arr.at(posToReplaceWith) < arr.at(i)) posToReplaceWith = i;

  swap(arr.at(posToReplaceWith), arr.at(n - 1));
  selectionSort(arr, n - 1);
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {2, 31, 1, 32, 0, -1, 88};
  selectionSort(arr, arr.size());
  for (const auto &n : arr) cout << n << " ";
  cout << endl;
  return 0;
}
