// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>

using namespace std;

int main (void) {
  int x;
  cin >> x;

  int ans = 0;
  while(x != 0) {
    int temp = x % 10;
    if ((ans > INT_MAX / 10 - temp / 10) || (ans < INT_MIN / 10 - temp / 10)) {
      cout << 0 << endl;
      return 0;
    } else {
    ans = ans * 10 + temp;
    }
    x /= 10;
  }

  cout << ans << endl;
}