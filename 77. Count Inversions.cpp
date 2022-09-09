// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
#define ll long long

using namespace std;

// logic is correct but not time optimized O(n ^ 2)
ll int inversionCount2(ll arr[], ll N) {
  ll count = 0;
  for (ll int i = 0; i < N - 1; ++i)
    count += count_if(arr + i + 1, arr + N, [&](ll j) { return j < arr[i]; });
  return count;
}

// optimized solution using merge sort O(nlogn)
ll merge(ll arr[], ll &start, ll &mid, ll &end) {
  ll i = start, j = mid + 1, ans = 0, pos = 0;
  ll temp[end - start + 1];

  while (i <= mid and j <= end) {
    if (arr[i] > arr[j]) {
      temp[pos] = arr[j++];
      ans += mid - i + 1;
    } else
      temp[pos] = arr[i++];
    pos++;
  }

  while (i != mid + 1) temp[pos++] = arr[i++];
  while (j != end + 1) temp[pos++] = arr[j++];

  copy(temp, temp + pos, arr + start);

  return ans;
}

ll solve(ll arr[], ll start, ll end) {
  if (start >= end) return 0;

  ll ans = 0;
  ll mid = start + (end - start) / 2;

  ans += solve(arr, start, mid);
  ans += solve(arr, mid + 1, end);
  ans += merge(arr, start, mid, end);

  return ans;
}

ll int inversionCount(ll arr[], ll N) { return solve(arr, 0, N - 1); }

int main(int argc, char const *argv[]) {
  ll arr[] = {2, 4, 1, 3, 5};
  cout << inversionCount(arr, 5) << endl;
  return 0;
}
