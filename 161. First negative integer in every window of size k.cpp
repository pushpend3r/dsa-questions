// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N,
                                            long long int K) {
  vector<long long> ans;
  queue<int> q;

  // process first window
  for (int i = 0; i < K; ++i)
    if (A[i] < 0) q.push(i);

  if (q.empty())
    ans.push_back(0);
  else
    ans.push_back(A[q.front()]);

  for (int i = K; i < N; ++i) {
    if (A[i] < 0) q.push(i);

    if (!q.empty() and q.front() <= i - K) q.pop();

    if (q.empty())
      ans.push_back(0);
    else
      ans.push_back(A[q.front()]);
  }

  return ans;
}

// approach 2 - O(N) [TC] and O(1) [SC]
vector<long long> printFirstNegativeInteger(long long int A[], long long int N,
                                            long long int K) {
  vector<long long> ans;
  ans.reserve(N);
  int idx = 0;

  for (auto i = K - 1; i < N; ++i) {
    // either idx outside of range or idx's element is negative
    // also we need to make sure it must be less than i
    while ((idx < i) and (idx <= i - K or A[idx] >= 0)) idx++;
    ans.push_back(A[idx] < 0 ? A[idx] : 0);
  }
  return ans;
}