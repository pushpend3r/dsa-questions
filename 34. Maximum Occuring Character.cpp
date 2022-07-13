// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#

#include <bits/stdc++.h>

using namespace std;

char getMaxOccuringChar(string str) {
  vector<int> count(128, 0);
  for (const auto &i : str) count.at(i)++;
  int max = INT_MIN, ans = -1;
  for (int i = 0; i < 128; ++i) {
    if (count.at(i) > max) {
      max = count.at(i);
      ans = i;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
