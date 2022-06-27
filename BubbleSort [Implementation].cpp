// https://www.codingninjas.com/codestudio/problems/bubble-sort_980524

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& arr, int n) {
  for (int round = 1; round < n; ++round) {
    bool isSwapped = false;
    for (int i = 0; i < n - round; ++i) {
      if (arr.at(i) > arr.at(i + 1)) {
        swap(arr.at(i), arr.at(i + 1));
        isSwapped = true;
      }
    }
    if (!isSwapped) break;
  }
}

int main(int argc, char const* argv[]) {
  vector<int> arr = {8, 22, 7, 9, 31, 5, 13};
  bubbleSort(arr, arr.size());
  for (auto i : arr) cout << i << " ";
  cout << endl;
  return 0;
}
