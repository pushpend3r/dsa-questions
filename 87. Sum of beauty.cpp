// https://practice.geeksforgeeks.org/contest/job-a-thon-13-hiring-challenge/problems/#

/*
Problem Statement -
Given a array find the total no of beauty of all of it subarrays
* beauty of a array = the number of elements in the subarray that occurs exactly
once.
* subarray = is any continuous part of the array

Input:
N = 3
arr[ ] = {2, 4, 2}
Output:  8
Explanation:
All possible subarrays are
{2} : beauty is 1.
{4} : beauty is 1.
{2} : beauty is 1.
{2, 4} : beauty is 2.
{4, 2} : beauty is 2.
{2, 4, 2}: beauty is 1.
The sum of all beauty is 1+ 1+ 1+ 2+ 2+ 1 = 8.

*/

#include <bits/stdc++.h>

using namespace std;

/* We are finding every element contributes of beauty in all subarrays where it
 * is inculeded */
long long calcBeauty(int n, vector<int> arr) {
  long long ans = 0;
  unordered_map<int, vector<int>> map;
  for (int i = 0; i < n; ++i) map[arr[i]].push_back(-1);
  for (int i = 0; i < n; ++i) map[arr[i]].push_back(i);
  for (auto &i : map) i.second.push_back(n);
  for (auto &i : map) {
    vector<int> &temp = i.second;
    int size = i.second.size();
    for (int j = 1; j < size - 1; ++j)
      ans += ((temp[j] - temp[j - 1]) * (temp[j + 1] - temp[j]));
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
