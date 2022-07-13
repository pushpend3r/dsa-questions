// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>

using namespace std;

// My Approach (Ugh..)
bool checkInclusion(string s1, string s2) {
  int n = s1.length(), m = s2.length();

  // s1 is bigger than s2
  if (n > m) return false;

  sort(s1.begin(), s1.end());

  for (int i = 0; i <= m - n; ++i) {
    string s = s2.substr(i, n);
    sort(s.begin(), s.end());
    if (s == s1) return true;
  }

  return false;
}

bool isPermutationEqual(string &str1, string &str2) {
  int charOccurences[26] = {0};
  for (int i = 0; i < str1.length(); ++i) {
    charOccurences[str1.at(i) - 'a']++;
    charOccurences[str2.at(i) - 'a']--;
  }

  for (const int &i : charOccurences)
    if (i) return false;

  return true;
}

// Approach 2
bool checkInclusion2(string s1, string s2) {
  int n = s1.length(), m = s2.length();

  for (int i = 0; i <= m - n; ++i) {
    string s = s2.substr(i, n);
    if (isPermutationEqual(s, s1)) return true;
  }

  return false;
}

// Approach 3
bool checkInclusion3(string s1, string s2) {
  int n = s1.length(), m = s2.length();

  vector<int> countOfCharInStr1(26, 0);
  for (const int &i : s1) countOfCharInStr1[i - 'a']++;

  vector<int> countOfCharInStr2(26, 0);
  for (const int &i : s2.substr(0, n)) countOfCharInStr2[i - 'a']++;

  if (countOfCharInStr1 == countOfCharInStr2) return true;
  int index = n;

  while (index < m) {
    countOfCharInStr2[s2.at(index - n) - 'a']--;
    countOfCharInStr2[s2.at(index) - 'a']++;

    if (countOfCharInStr1 == countOfCharInStr2) return true;
    index++;
  }

  return false;
}

// Approach 4
bool checkInclusion4(string s1, string s2) {
  int n = s1.length(), m = s2.length(), i = n;

  vector<int> count(26, 0);
  for (const int &i : s1) count.at(i - 'a')++;
  for (const int &i : s2.substr(0, n)) count.at(i - 'a')--;

  // check if whole vector's elements are zero
  if (!any_of(count.begin(), count.end(), [](int &i) { return i != 0; }))
    return true;

  while (++i < m) {
    count[s2.at(i - n) - 'a']++;
    count[s2.at(i) - 'a']--;
    // check if whole vector's elements are zero
    if (!any_of(count.begin(), count.end(), [](int &i) { return i != 0; }))
      return true;
  }

  return false;
}

// Approach 5
bool checkInclusion5(string s1, string s2) {
  int n = s1.length(), m = s2.length(), i = n - 1;

  vector<int> count(26, 0);
  for (const int &i : s1) count.at(i - 'a')++;
  for (const int &i : s2.substr(0, n)) count.at(i - 'a')--;

  while (1) {
    // check if whole vector's elements are zero
    if (!any_of(count.begin(), count.end(), [](int &i) { return i != 0; }))
      return true;
    if (++i >= m) break;
    count[s2.at(i - n) - 'a']++;
    count[s2.at(i) - 'a']--;
  }

  return false;
}

int main(int argc, char const *argv[]) {
  cout << boolalpha << checkInclusion4("adc", "dcda") << endl;
  return 0;
}
