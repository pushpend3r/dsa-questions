// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380914

#include <bits/stdc++.h>

using namespace std;

bool solve(int n, long long int k) {
  if (n == 1) return true;
  bool parent = solve(n - 1, (k + 1) / 2);
  // left child will always be odd
  if (k & 1) return parent;
  // right child
  return !parent;
  // OR
  // return k & 1 ? parent : !parent;
}

string kthChildNthGeneration(int n, long long int k) {
  return solve(n, k) ? "Male" : "Female";
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
