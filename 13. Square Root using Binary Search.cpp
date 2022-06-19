// https://www.codingninjas.com/codestudio/problems/square-root_893351

#include <bits/stdc++.h>

using namespace std;

// gives the integer part
int sqrtUsingBinarySearch(long long int N)
{
  long long int start = 0, end = N, mid;
  unsigned long long int tempSqrt;
  int ans = -1;

  while (start <= end)
  {
    mid = start + (end - start) / 2;
    tempSqrt = mid * mid;

    if (tempSqrt == N)
      return mid;

    if (tempSqrt < N)
    {
      ans = mid;
      start = mid + 1;
    }
    else
      end = mid - 1;
  }

  return ans;
}

// Love Babber's Approach
double sqrtUsingBinarySearchWithPrecision(long long int N, int precision)
{
  double sqrtRoot = sqrtUsingBinarySearch(N);
  double factor = 1;

  for (int i = 0; i < precision; ++i)
  {
    factor = factor / 10;
    for (double j = sqrtRoot; j * j < N; j = j + factor)
      sqrtRoot = j;
  }

  return sqrtRoot;
}

// My Approach - little lengthy but I did it anyways
double sqrtUsingBinarySearchWithPrecision2(long long int N, int precision)
{
  int sqrtRootIntegerPart = sqrtUsingBinarySearch(N);

  double factor = 1;
  double decimalValue = 1;

  for (int i = 0; i < precision; ++i)
  {
    factor /= 10;
    decimalValue *= 10;
  }

  double start = factor, end = 1 - factor, mid, ans = 0;

  while (start <= end)
  {
    // making the mid to precision only. suppose if it 0.1875 and precision is 3 then it would be 0.187
    mid = (double)((int)((start + (end - start) / 2) * decimalValue)) / decimalValue;

    long long int tempSqrt = (sqrtRootIntegerPart + mid) * (sqrtRootIntegerPart + mid);

    if (tempSqrt < N)
    {
      ans = mid;
      start = mid + factor;
    }
    else
    {
      end = mid - factor;
    }
  }

  return sqrtRootIntegerPart + ans;
}

double sqrtN(long long int N)
{
  return sqrtUsingBinarySearchWithPrecision(N, 3);
}

int main(int argc, char const *argv[])
{
  cout << sqrtUsingBinarySearchWithPrecision(27, 3) << endl;
  cout << sqrtUsingBinarySearchWithPrecision2(27, 3) << endl;
  return 0;
}
