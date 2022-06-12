// https://leetcode.com/problems/power-of-two/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  double powof2 = log2(n);

  if (powof2 == int(powof2))
    cout << "Yes";
  else
    cout << "No";

  cout << endl;
}