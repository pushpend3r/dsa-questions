// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380915?leftPanelTab=1

#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<int> &ans) {
  if (n <= 0) {
    ans.push_back(n);
    return;
  }
  ans.push_back(n);
  solve(n - k, k, ans);
  ans.push_back(n);
}

vector<int> printSeries(int n, int k) {
  vector<int> ans;
  solve(n, k, ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
