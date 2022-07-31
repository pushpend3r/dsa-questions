// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/3583551/problems/14818

#include <bits/stdc++.h>

using namespace std;

// Approach 1 (got TLE) - use bubblesort
int classTest(int n, vector<int> &a, int k) {
  for (int round = 1; round <= k; ++round) {
    for (int i = 0; i < n - round; i++)
      if (a.at(i) > a.at(i + 1)) swap(a.at(i), a.at(i + 1));
  }

  return a.at(n - k);
}

// Approach 2 (got TLE)
int classTest(int n, vector<int> &a, int k) {
  // true = asc
  // false = desc
  bool order = true;

  if (n - k + 1 < k) {
    k = n - k + 1;
    order = false;
  }

  for (int round = 1; round <= k; ++round) {
    for (int i = 0; i < n - round; i++) {
      if (order) {
        if (a.at(i) > a.at(i + 1)) swap(a.at(i), a.at(i + 1));
      } else if (a.at(i) < a.at(i + 1))
        swap(a.at(i), a.at(i + 1));
    }
  }

  return a.at(n - k);
}

// Approach 3
int classTest(int n, vector<int> &a, int k) {
  sort(a.begin(), a.end());
  return a.at(n - k);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
