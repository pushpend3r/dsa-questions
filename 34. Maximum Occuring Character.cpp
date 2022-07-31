// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#

#include <bits/stdc++.h>

using namespace std;

// Approach 1
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

// Approach 2
char getMaxOccuringChar(string str) {
  vector<int> count(26, 0);
  for (const auto &i : str) count.at(tolower(i) - 'a')++;
  return max_element(count.begin(), count.end()) - count.begin() + 'a';
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
