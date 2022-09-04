// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380915

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

// see operator precedence and implict type casting for better understanding
// 1LL for long long
int pow(int x, int n) {
  if (n == 0) return 1;
  if (n & 1) return 1LL * x * pow(x, n - 1) % MOD;
  return pow(1LL * x * x % MOD, n / 2);
}

int nthTermOfGP2(int N, int A, int R) { return 1LL * A * pow(R, N - 1) % MOD; }

// Overflow will happens as recursive calls will be higher
// but logic is correct
int nthTermOfGP(int N, int A, int R) {
  if (N == 1) return A;
  return R * nthTermOfGP(N - 1, A, R);
}

int main(int argc, char const *argv[]) {
  cout << nthTermOfGP2(5, 3, 2) << endl;
  return 0;
}
