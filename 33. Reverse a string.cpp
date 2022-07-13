// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <bits/stdc++.h>

using namespace std;

void reverse(string &s, int start, int end) {
  while (start < end) swap(s.at(start++), s.at(end--));
}

string reverseWords(string s) {
  int wordStartIndex = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s.at(i) == ' ') {
      reverse(s, wordStartIndex, i - 1);
      wordStartIndex = i + 1;
    }
  }
  reverse(s, wordStartIndex, s.size() - 1);
  return s;
}

int main(int argc, char const *argv[]) {
  cout << reverseWords("Let's take LeetCode contest") << endl;
  return 0;
}
