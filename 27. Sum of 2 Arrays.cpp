// https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186

#include <bits/stdc++.h>

using namespace std;

// My Approach
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m) {
  vector<int> ans;
  int dividend = 0;
  int remainder = 0;
  int tempSum = 0;

  while (n > 0 or m > 0) {
    tempSum = (n > 0 ? a.at(n - 1) : 0) + (m > 0 ? b.at(m - 1) : 0) + dividend;
    dividend = tempSum / 10;
    remainder = tempSum % 10;
    ans.push_back(remainder);
    n--, m--;
  }

  if (dividend) ans.push_back(dividend);

  reverse(ans.begin(), ans.end());

  return ans;
}

// Approach 2
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m) {
  vector<int> ans;
  int sumA = 0, sumB = 0;

  for (auto &i : a) sumA = sumA * 10 + i;
  for (auto &i : b) sumB = sumB * 10 + i;

  int totalSum = sumA + sumB;

  while (totalSum) {
    ans.push_back(totalSum % 10);
    totalSum /= 10;
  }

  reverse(ans.begin(), ans.end());

  return ans;
}

int main(int argc, char const *argv[]) {
  int t, n, m;
  cin >> t >> n >> m;
  while (t--) {
    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : findArraySum(a, n, b, m)) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
