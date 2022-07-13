// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <bits/stdc++.h>

using namespace std;

// My Approach
string removeOccurrences(string str, string part) {
  for (int i = 0; i < str.length(); ++i) {
    if (str.at(i) == part.at(0) and
        !str.substr(i, part.length()).compare(part)) {
      str.erase(i, part.length());
      i = i - part.length();
      if (i < 0) i = -1;
    }
  }

  return str;
}

// Approach 2
string removeOccurrences2(string str, string part) {
  while (1) {
    int index = str.find(part);
    // no occurences left
    if (index == -1) return str;
    str.erase(index, part.length());
  }
}

// Approach 3 (2's improved version)
string removeOccurrences3(string str, string part) {
  int index = 0;
  while (1) {
    index = str.find(part, index);
    // no occurences left
    if (index == -1) return str;
    str.erase(index, part.length());
    index -= part.length();
    if (index < 0) index = 0;
  }
}

// Approach 4
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/discuss/1298766/C%2B%2B-Simple-solution-Faster-than-100
string removeOccurrences4(string s, string part) {
  string x = s;
  int n = s.length(), m = part.length(), i, j;
  for (i = 0, j = 0; i < n; i++) {
    x[j++] = s[i];
    if (j >= m and x.substr(j - m, m) == part) j -= m;
  }
  return x.substr(0, j);
}

int main(int argc, char const *argv[]) {
  cout << removeOccurrences4("daabcbaabcbc", "abc") << endl;
  return 0;
}
