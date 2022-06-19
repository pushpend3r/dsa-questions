// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

int pivotIndex(vector<int> &nums)
{
  int start = 0, end = nums.size() - 1, mid = start + (end - start) / 2;

  while (start < end)
  {
    if (nums.at(0) <= nums.at(mid))
      start = mid + 1;
    else
      end = mid;

    mid = start + (end - start) / 2;
  }

  return start;
}

// Approach 1
int search(vector<int> &nums, int target)
{
  int pivotIndexNo = pivotIndex(nums);

  int start = 0, end = nums.size() - 1;

  if (nums.at(pivotIndexNo) <= target and target <= nums.at(end))
    start = pivotIndexNo;
  else
    end = pivotIndexNo - 1;

  int mid = start + (end - start) / 2;

  while (start <= end)
  {
    if (nums.at(mid) == target)
      return mid;

    if (nums.at(mid) < target)
      start = mid + 1;
    else
      end = mid - 1;

    mid = start + (end - start) / 2;
  }

  return -1;
}

// Approach 2
int search(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    if (nums[mid] == target)
      return mid;

    // Go to Left
    if (nums[start] <= nums[mid])
    {
      if (target >= nums[start] && target < nums[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
    // Go to Right
    else
    {
      if (target > nums[mid] && target <= nums[end])
        start = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << search(nums, 0) << endl;
  return 0;
}
