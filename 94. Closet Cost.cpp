// https://www.codingninjas.com/codestudio/problems/closest-cost_3758281

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &gifts, int temp, int index, int &X, vector<int> &sums) {
  if (index >= gifts.size()) {
    sums.push_back(temp);
    return;
  }

  if (temp + gifts.at(index) * 2 < X)
    solve(gifts, temp + gifts.at(index) * 2, index + 1, X, sums);

  if (temp + gifts.at(index) < X)
    solve(gifts, temp + gifts.at(index), index + 1, X, sums);

  solve(gifts, temp, index + 1, X, sums);
}

int closestCost(int N, int M, int X, vector<int> W, vector<int> G) {
  vector<int> sums;
  int ans = INT_MAX, diff = INT_MAX;
  solve(G, 0, 0, X, sums);

  for (const auto &i : W) {
    for (const auto &j : sums) {
      int temp = abs(X - (i + j));
      if (temp < diff) {
        diff = temp;
        ans = i + j;
      } else if (temp == diff and ans > i + j) {
        ans = i + j;
      }
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
