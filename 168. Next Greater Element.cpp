// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include <bits/stdc++.h>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
  vector<long long> ans;
  stack<long long> s;

  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() and s.top() <= arr[i]) s.pop();
    s.empty() ? ans.push_back(-1) : ans.push_back(s.top());
    s.push(arr[i]);
  }

  reverse(ans.begin(), ans.end());

  return ans;
}