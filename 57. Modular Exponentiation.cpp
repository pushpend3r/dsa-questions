// https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146

#include <bits/stdc++.h>

using namespace std;

int modularExponentiation(int x, int n, int m) {
  int ans = 1;
  while (n > 0) {
    // alternative to n % i == 0
    if (n & 1) ans = (1LL * ans * (x) % m) % m;
    x = (1LL * (x % m) * (x % m)) % m;
    // faster way of division by 2
    n >>= 1;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
