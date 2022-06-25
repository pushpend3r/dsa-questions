// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-l/problems/14804

#include <bits/stdc++.h>

using namespace std;

long long appleAndCoupon(int n, int m, vector<int> arr) {
  long long sum = accumulate(arr.begin(), arr.end(), 0);
  sort(arr.begin(), arr.end());
  auto ans = sum - arr.at(arr.size() - m);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
