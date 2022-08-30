#include <bits/stdc++.h>
#define MOD 1000000007

int factorial(int n) {
  for (int i = n - 1; i >= 2; --i) {
    n = ((1LL * n) * i) % MOD;
  }
  return n;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
