// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1

#include <bits/stdc++.h>

using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
  vector<int> ans;
  ans.reserve(n);

  deque<int> q;

  int index = 0;

  while (index < k) {
    while (!q.empty() and arr[q.back()] < arr[index]) q.pop_back();
    q.push_back(index);
    index++;
  }

  ans.push_back(arr[q.front()]);

  while (index < n) {
    while (!q.empty() and q.front() <= index - k) q.pop_front();
    while (!q.empty() and arr[q.back()] < arr[index]) q.pop_back();
    q.push_back(index);
    index++;
    ans.push_back(arr[q.front()]);
  }

  return ans;
}