// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-3/3743976/problems/16572?leftPanelTab=0

#include <bits/stdc++.h>

using namespace std;

int makeItEqual(int a, int b, int c) {
  int ans = 0;
  bool a1, a2, a3;

  while (a or b or c) {
    a1 = a & 1;
    a2 = b & 1;
    a3 = c & 1;

    if (a3) {
      if (!a1 and !a2) ans += 2;
      if (a1 ^ a2) ans += 1;
    } else {
      if (a1 & a2) ans += 1;
    }

    a >>= 1;
    b >>= 1;
    c >>= 1;
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
