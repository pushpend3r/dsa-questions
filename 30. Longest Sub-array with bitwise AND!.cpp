// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/3583551/problems/14871

#include <bits/stdc++.h>

using namespace std;

// My Approach
vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries) {
  // Bitwise AND
  for (int i = 1; i < n; ++i) arr.at(i) = arr.at(i) & arr.at(i - 1);

  vector<int> ans;
  int tempAns, start, end, mid;

  for (int i = 0; i < q; ++i) {
    tempAns = -1;
    start = 0, end = n - 1;

    while (start <= end) {
      mid = start + (end - start) / 2;
      if (arr.at(mid) >= queries[i]) {
        tempAns = mid;
        start = mid + 1;
      } else
        end = mid - 1;
    }

    ans.push_back(tempAns + 1);
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
