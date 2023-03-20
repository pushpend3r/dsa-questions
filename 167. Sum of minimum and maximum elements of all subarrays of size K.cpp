// https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047

#include <bits/stdc++.h>
#define ll long long

using namespace std;

// approach 1 - using deque and sliding window concept
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
  deque<int> maxq;
  deque<int> minq;
  long long ans = 0;

  int index = 0;

  // process first k elements
  while (index < k) {
    while (!minq.empty() and nums[minq.back()] >= nums[index]) minq.pop_back();
    while (!maxq.empty() and nums[maxq.back()] < nums[index]) maxq.pop_back();

    maxq.push_back(index);
    minq.push_back(index);

    index++;
  }

  ans += nums[maxq.front()];
  ans += nums[minq.front()];

  while (index < n) {
    while (!minq.empty() and minq.front() <= index - k) minq.pop_front();
    while (!minq.empty() and nums[minq.back()] >= nums[index]) minq.pop_back();

    while (!maxq.empty() and maxq.front() <= index - k) maxq.pop_front();
    while (!maxq.empty() and nums[maxq.back()] < nums[index]) maxq.pop_back();

    maxq.push_back(index);
    minq.push_back(index);

    index++;

    ans += nums[maxq.front()];
    ans += nums[minq.front()];
  }

  return ans;
}

ll max_total(vector<int> &nums, int n, int k) {
  list<ll> li;
  ll ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    while (!li.empty() && nums[j] > li.back()) {
      li.pop_back();
    }
    li.push_back(nums[j]);
    if (j - i + 1 < k) {
      j++;
    } else if (j - i + 1 == k) {
      ans += li.front();
      if (li.front() == nums[i]) {
        li.pop_front();
      }
      i++;
      j++;
    }
  }
  return (ans);
}

ll min_total(vector<int> &nums, int n, int k) {
  list<ll> li;
  ll ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    while (!li.empty() && nums[j] < li.back()) {
      li.pop_back();
    }
    li.push_back(nums[j]);
    if (j - i + 1 < k) {
      j++;
    } else if (j - i + 1 == k) {
      ans += li.front();
      // means front element is outside of the next range
      if (li.front() == nums[i]) {
        li.pop_front();
      }
      i++;
      j++;
    }
  }
  return (ans);
}

// approach 2
ll sumOfMaxAndMin(vector<int> &nums, int n, int k) {
  ll max_sum = max_total(nums, n, k);
  ll min_sum = min_total(nums, n, k);
  return (max_sum + min_sum);
}
