// https://www.codingninjas.com/codestudio/problems/ninja-technique_2279868

#include <bits/stdc++.h>

using namespace std;

int ninjaTechnique(int n, vector<vector<int>> &a) {
  for (auto &i : a)
    if (i.at(0) > i.at(1)) swap(i.at(0), i.at(1));

  sort(a.begin(), a.end(),
       [](vector<int> &i, vector<int> &j) { return i.at(0) < j.at(0); });

  int temp = INT_MIN, ans = 0;

  for (const auto &i : a) {
    if (i.at(0) > temp) {
      ans++;
      temp = i.at(1);
    } else {
      temp = min(temp, i.at(1));
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> a = {{0, 2}, {2, 5}};
  cout << ninjaTechnique(a.size(), a);
  return 0;
}
