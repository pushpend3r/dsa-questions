// https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055

#include <bits/stdc++.h>

using namespace std;

// My Approach (got TLE 😔)
void sort012(int *arr, int n)
{
  int start = 0;
  int end = n - 1;

  while (start < end)
  {
    if (arr[start] == 0)
      start++;
    else if (arr[end] == 2)
      end--;
    else if (arr[start] == 1 and arr[end] == 1)
    {
      int tempIndex = start;
      do
      {
        tempIndex++;
      } while (tempIndex < end and arr[tempIndex] == 1);
      if (tempIndex == end)
      {
        start = end;
      }
      swap(arr[tempIndex], arr[start]);
    }
    else
    {
      swap(arr[start], arr[end]);
    }
  }
}

// Approach 1
void sort012(int *arr, int n)
{
  int low = 0, high = n - 1;

  for (int i = 0; i < n; i++)
  {
    while (arr[low] == 0)
      low++;
    while (arr[high] == 2)
      high--;
    if (arr[i] == 2 && i < high)
      swap(arr[i], arr[high]);
    if (arr[i] == 0 && i > low)
      swap(arr[i], arr[low]);
  }
}

// Approach 2 (Best)
void sort012(int *arr, int n)
{
  int start = 0, mid = 0, end = n - 1;

  while (mid <= end)
  {
    if (arr[mid] == 1)
      mid++;
    else if (arr[mid] == 2)
    {
      swap(arr[mid], arr[end]);
      end--;
    }
    else
    {
      swap(arr[mid], arr[start]);
      start++;
      mid++;
    }
  }
}

int main(void)
{
  int t, n;
  cin >> t;

  while (t--)
  {
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i)
      cin >> arr[i];

    sort012(arr, n);
  }
}