// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/problems/15566

#include <bits/stdc++.h>

using namespace std;

// did the silly mistake when reading the question I thought P ^ i means P XOR i
// but it was P to the power i
string binaryShopping(string S, int P) {
  int OnesCount = 0;
  for (int i = S.length() - 1; i > 0; --i) {
    if (S.at(i) == '1') {
      S.at(i) = '0';
      OnesCount++;
    }

    if (OnesCount == 2) break;
  }

  if (OnesCount == 2 or OnesCount == 0) return S;

  S.at(0) = S.at(0) == '0' ? '1' : '0';

  return S;
}

int main(int argc, char const *argv[]) {
  binaryShopping("01101", 3);
  return 0;
}
