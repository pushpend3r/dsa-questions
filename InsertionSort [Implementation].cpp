// https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179

#include <bits/stdc++.h>

using namespace std;

void insertionSort(int n, vector<int> &arr) {
  for (int round = 1; round < n; ++round) {
    auto temp = arr.at(round);
    int i = round - 1;
    while (i >= 0) {
      if (arr.at(i) > temp)
        arr.at(i + 1) = arr.at(i);
      else
        break;
      i--;
    }
    arr.at(i + 1) = temp;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
