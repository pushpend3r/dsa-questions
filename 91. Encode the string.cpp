// https://www.codingninjas.com/codestudio/problems/encode-the-string_3651409

#include <bits/stdc++.h>

using namespace std;

string encodeString(string &s, int n) {
  for (auto &i : s) {
    if (i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u')
      i++;
    else
      i--;
  }

  return s;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
