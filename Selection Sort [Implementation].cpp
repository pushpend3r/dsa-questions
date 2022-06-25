#include <bits/stdc++.h>

using namespace std;

// using STL
void selectionSort(vector<int> &arr) {
  for (int round = 1; round < arr.size(); ++round) {
    swap(arr.at(round - 1),
         arr.at(min_element(arr.begin() + round - 1, arr.end()) - arr.begin()));
  }
}

// raw implementation
void selectionSort2(vector<int> &arr) {
  int i, pos, positionToBeReplacedWith;
  for (int round = 1; round < arr.size(); ++round) {
    i = round, pos = round - 1, positionToBeReplacedWith = round - 1;
    while (i < arr.size()) {
      if (arr.at(positionToBeReplacedWith) > arr.at(i))
        positionToBeReplacedWith = i;
      i++;
    }
    swap(arr.at(pos), arr.at(positionToBeReplacedWith));
  }
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {2, 31, 1, 32, 0, -1, 88};
  selectionSort2(arr);
  for (const auto &n : arr) cout << n << " ";
  cout << endl;
  return 0;
}
