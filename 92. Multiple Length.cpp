// https://www.codingninjas.com/codestudio/problems/multiple-length_2547237

#include <bits/stdc++.h>

using namespace std;

// Approach 1 (product overflow happens)
int multipleLength1(vector<int> &a, int n) {
  unsigned long long product = 1;
  for (const auto &i : a) product *= i;
  return 1 + (int)log2(product);
}

// Approach 2
/*
-> Why it works?
Properties of Log Base 2
** Product Rule ** : log2 MN = log2 M + log2 N
Example : log 30 + log 2 = log 60

** Quotient Rule ** : log2 M/N = log2 M – log2 N
*/
int multipleLength(vector<int> &a, int n) {
  double ans = 0;
  for (const auto &i : a) ans += log2(i);
  return (int)ans + 1;
}

int main(int argc, char const *argv[]) {
  vector<int> a = {4, 4};
  cout << multipleLength(a, a.size()) << endl;
  return 0;
}
