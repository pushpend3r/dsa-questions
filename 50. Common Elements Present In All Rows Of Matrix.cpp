// https://www.codingninjas.com/codestudio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111

#include <bits/stdc++.h>

using namespace std;

// naive approach (got accepted on CodeStudio)
vector<int> findCommonElements(vector<vector<int>> &mat) {
  unordered_set<int> ans;
  int n = mat.size(), m = mat.at(0).size();
  bool flag;
  for (int i = 0; i < m; ++i) {
    flag = 0;
    for (int j = 1; j < n; ++j) {
      if (!any_of(mat.at(j).begin(), mat.at(j).end(),
                  [&](int &ele) { return ele == mat.at(0).at(i); })) {
        flag = true;
        break;
      }
    }
    if (!flag) ans.insert(mat.at(0).at(i));
  }
  vector<int> finalans(ans.begin(), ans.end());
  return finalans;
}

// struct hashFunction {
//   size_t operator()(const pair<int, int> &x) const { return x.first; }
// };
// unordered_set<pair<int, int>, hashFunction> ans;

// Approach 2
vector<int> findCommonElements(vector<vector<int>> &mat) {
  unordered_map<int, int> counts;
  vector<int> ans;
  int n = mat.size();

  // Finding the count of elements
  for (int i = 0; i < n; ++i)
    for (const auto &element : mat.at(i))
      if (counts[element] == i) counts[element]++;

  // filtering element whose count is equal to total rows
  for (const auto &i : counts)
    if (i.second == n) ans.push_back(i.first);

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
