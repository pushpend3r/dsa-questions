// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>

using namespace std;

// My Approach
int pivotIndex(vector<int> &nums)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);

  int leftSum = 0, rightSum = sum;

  int size = nums.size();

  for (int i = 0; i < size; ++i)
  {
    if (i != 0)
      leftSum += nums.at(i - 1);
    rightSum -= nums.at(i);
    if (leftSum == rightSum)
      return i;
  }

  return -1;
}

// Approach - bit better than mine
int pivotIndex(vector<int> &nums)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);

  int leftSum = 0, rightSum = sum;

  int size = nums.size();

  for (int i = 0; i < size; ++i)
  {
    rightSum -= nums.at(i);
    if (leftSum == rightSum)
      return i;
    leftSum += nums.at(i);
  }

  return -1;
}

// Approach 2 - bit modifiy version previous ones
int pivotIndex(vector<int> &nums)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);

  int leftSum = 0;

  int size = nums.size();

  for (int i = 0; i < size; ++i)
  {
    if (leftSum == sum - nums.at(i) - leftSum)
      return i;
    leftSum += nums.at(i);
  }

  return -1;
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
