#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int k, int size)
{
  int start = 0, end = size - 1, mid = (start + end) / 2;

  // this mid variable could suffer from integer overflow problem,
  // start + end could exceed from integer limits
  // solution is to use start + (end - start) / 2 instead
  // do math it will end up (start + end) / 2.

  while (start <= mid and mid <= end)
  {
    if (arr[mid] == k)
      return mid;

    if (arr[mid] < k)
      start = mid + 1;
    else
    {
      end = mid - 1;
    }

    mid = (start + end) / 2;
  }

  return -1;
}

void printArray(int arr[], int size)
{
  int len = size - 1;

  for (int i = 0; i <= len; ++i)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int main(int argc, char const *argv[])
{
  int arr[6] = {-3, -2, 1, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  cout << binarySearch(arr, 6, size) << endl;
  cout << binarySearch(arr, -3, size) << endl;
  cout << binarySearch(arr, -5, size) << endl;
  cout << binarySearch(arr, 8, size) << endl;

  return 0;
}
