#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &pages, int m, int numPages) {
  int cntStudents = 1;
  int curSum = 0;
  int n = pages.size();
  for (int i = 0; i < n; i++) {
    if (curSum + pages[i] > numPages) {
      cntStudents += 1;
      curSum = pages[i];
      if (cntStudents > m) return false;
    } else
      curSum += pages[i];
  }

  return true;
}

int allocateBooks(vector<int> &pages, int m) {
  if (pages.size() < m) return -1;

  int sum = accumulate(pages.begin(), pages.end(), 0);

  for (int numPages = 1; numPages <= sum; numPages++)
    if (isPossible(pages, m, numPages)) return numPages;

  return -1;
}

int main() {
  int m = 2;
  vector<int> pages = {10, 20, 30, 40};
  cout << "The minimum value of the maximum number of pages in book allocation "
          "is: "
       << allocateBooks(pages, m) << endl;
}