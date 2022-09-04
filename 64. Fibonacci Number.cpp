// https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
  if (n == 1) return 1;
  if (n == 0) return 0;
  return fib(n - 1) + fib(n - 2);
}

// iterative bottom up DP
int fib(int n) {
  if (n == 1) return 1;
  if (n == 0) return 0;
  int fib_n_minus_1 = 1, fib_n_minus_2 = 0;
  for (int i = 2; i < n; i++) {
    int temp = fib_n_minus_1 + fib_n_minus_2;
    fib_n_minus_2 = fib_n_minus_1;
    fib_n_minus_1 = temp;
  }
  return fib_n_minus_1 + fib_n_minus_2;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
