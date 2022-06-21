// https://www.codingninjas.com/codestudio/problems/allocate-books_1090540

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &pages, int m, int numPages) {
  // which no of student will get next alottment
  int cntStudents = 1;
  // this will always contains value less than equals to numpages
  int curSum = 0;
  int n = pages.size();
  for (int i = 0; i < n; i++) {
    // no single element must not be more than numPages
    if (pages[i] > numPages) return false;

    // once sum is exceeding than numpages means it is time to stop and give
    // books to another kid
    if (curSum + pages[i] > numPages) {
      cntStudents += 1;
      curSum = pages[i];
      if (cntStudents > m) return false;
    } else
      curSum += pages[i];
  }

  return true;
}

int allocateBooksBruteForce(vector<int> &pages, int m) {
  if (pages.size() < m) return -1;

  // sum all array values
  int sum = accumulate(pages.begin(), pages.end(), 0);

  // 1 to sum will be our answer space.
  for (int numPages = 1; numPages <= sum; numPages++)
    if (isPossible(pages, m, numPages)) return numPages;

  return -1;
}

int allocateBooksBinarySearch(vector<int> &pages, int m) {
  if (pages.size() < m) return -1;

  // sum all array values
  int sum = accumulate(pages.begin(), pages.end(), 0);

  // 1 to sum will be our answer space.
  int start = 1, end = sum, mid, ans = -1;

  while (start <= end) {
    mid = start + (end - start) / 2;

    auto tempOutput = isPossible(pages, m, mid);

    if (tempOutput == 1) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return ans;
}

int main() {
  int m = 2;
  vector<int> pages = {10, 20, 30, 40};
  cout << "The minimum value of the maximum number of pages in book allocation "
          "is: "
       << allocateBooksBruteForce(pages, m) << endl;
  cout << "The minimum value of the maximum number of pages in book allocation "
          "is: "
       << allocateBooksBinarySearch(pages, m) << endl;
}