#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
  if (n == 1) return true;

  for (int i = 2; i < n; ++i)
    if (n % i == 0) return false;

  return true;
}

bool isPrime2(int n) {
  if (n == 1) return true;

  // we are using sqrt here because after sqrt factors of n will be just reverse
  /*
  suppose n = 36
  1 x 36
  2 x 18
  3 x 12
  4 x 9
  6 x 6
  9 x 4
  12 x 3
  18 x 2
  36 x 1
   */
  for (int i = 2; i <= sqrt(n); ++i)
    if (n % i == 0) return false;

  return true;
}

// Naive Approach
int countPrimes(int n) {
  int count = 0;
  for (int i = 2; i < n; ++i) {
    if (isPrime(i)) count++;
  }
  return count;
}

// -----------------------------

// Sieve of Eratosthenes
int countPrimes2(int n) {
  if (n <= 2) return 0;

  vector<bool> prime(n, true);
  prime.at(0) = prime.at(1) = false;

  for (int i = 2; i * i < n; i++)
    if (prime[i])
      for (int j = i * i; j < n; j += i) prime[j] = false;

  // counting prime numbers
  int primeCount = 0;
  for (int i = 2; i < n; i++)
    if (prime[i]) primeCount++;

  return primeCount;
}

// -----------------------------

vector<int> simpleSieve(int n) {
  vector<bool> prime(n + 1, true);
  prime.at(0) = prime.at(1) = false;

  for (int i = 2; i * i <= n; i++)
    if (prime[i])
      for (int j = i * i; j <= n; j += i) prime[j] = false;

  // counting prime numbers
  vector<int> ans;
  for (int i = 2; i <= n; i++)
    if (prime[i]) ans.push_back(i);

  return ans;
}

// Segmented Sieve
int countPrimes3(int n) {
  if (n <= 2) return 0;

  int limit = sqrt(n) + 1, low = limit + 1, high = 2 * limit, count;
  auto primes = simpleSieve(limit);
  count = primes.size();

  while (low < n) {
    if (high >= n) high = n - 1;
    vector<bool> marking(high - low + 1, true);

    for (const auto &i : primes) {
      // Find the minimum number in [low..high] that is
      // a multiple of prime[i] (divisible by prime[i])
      // For example, if low is 31 and prime[i] is 3,
      // we start with 33.
      int loLim = floor(low / i) * i;
      if (loLim < low) loLim += i;

      for (int j = loLim; j <= high; j += i) marking[j - low] = false;
    }

    for (const auto &i : marking)
      if (i) count++;

    low += limit;
    high += limit;
  }

  return count;
}

int main(int argc, char const *argv[]) {
  cout << countPrimes3(1) << endl;
  return 0;
}
