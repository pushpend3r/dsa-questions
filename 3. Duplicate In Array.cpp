// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397

#include <bits/stdc++.h>

using namespace std;

// My Approach
int findDuplicate(vector<int> &arr)
{
  bool isPresent[arr.size()] = {false};

  for (int i = 0; i < arr.size(); ++i)
  {
    if (isPresent[arr[i]])
      return arr[i];

    isPresent[arr[i]] = true;
  }
}

// Approach 2
int findDuplicate(vector<int> &arr)
{
  int ans = 0;

  // Calculate the whole array XOR which will eliminate the duplicate element.
  for (int i = 0; i < arr.size(); ++i)
  {
    ans ^= arr[i];
  }

  // Now to all 1 to N-1 XOR
  for (int i = 1; i < arr.size(); ++i)
  {
    ans ^= i;
  }

  return ans;
}

// Approach 3
int findDuplicate(vector<int> &arr)
{
  int sum = 0;
  int n = arr.size();

  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
  }

  int sumOfOneToN = (n * (n - 1)) / 2;

  return sum - sumOfOneToN;
}

int main(void)
{
}