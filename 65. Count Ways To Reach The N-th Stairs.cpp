// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

// Naive
int countDistinctWays(int nStairs) {
  if (nStairs < 0) return 0;
  if (nStairs == 0) return 1;
  return (1LL * countDistinctWays(nStairs - 1) +
          countDistinctWays(nStairs - 2)) %
         MOD;
}

// Using DP (Dynamic Programming)
int solve(int nStairs, vector<int> &steps) {
  if (nStairs == 0) return 1;
  if (nStairs < 0) return 0;

  if (steps.at(nStairs) != -1) return steps.at(nStairs);

  return steps.at(nStairs) =
             (1LL * solve(nStairs - 1, steps) + solve(nStairs - 2, steps)) %
             MOD;
}

int countDistinctWays(int nStairs) {
  vector<int> steps(100001, -1);
  return solve(nStairs, steps);
}

int main(int argc, char const *argv[]) {
  cout << countDistinctWays(2) << endl;
  return 0;
}
