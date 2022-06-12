#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int arr[5];
  long long int sum = 0;

  for (int &n : arr)
  {
    cin >> n;
  }

  for (const int &n : arr)
  {
    sum += n;
  }

  cout << sum << endl;

  return 0;
}