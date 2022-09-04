// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380915?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr, int pos, int k, vector<vector<int>> &ans,
           vector<int> subarray = {}) {
  // remember to tackle case like suppose k = 3 and arr = [1,2,3,-1,1]

  // traversed the whole array
  // as arr can contain negative values too..
  if (pos == arr.size()) {
    // found the subset
    if (k == 0) ans.push_back(subarray);
    return;
  }

  // not including the current position element
  solve(arr, pos + 1, k, ans, subarray);
  subarray.push_back(arr.at(pos));
  // including the current position element
  solve(arr, pos + 1, k - subarray.back(), ans, subarray);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
  vector<vector<int>> ans;
  solve(arr, 0, k, ans);
  return ans;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {2, 4, 6};
  int k = 6;
  for (const auto &i : findSubsetsThatSumToK(arr, arr.size(), k)) {
    for (const auto &j : i) cout << j << " ";
    cout << endl;
  }
  return 0;
}
