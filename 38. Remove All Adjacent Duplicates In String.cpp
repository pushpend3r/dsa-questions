// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>

using namespace std;

// Approach 1 [naive]
string removeDuplicates(string s) {
  for (int i = 1; i < s.length(); ++i) {
    if (s.at(i) == s.at(i - 1)) {
      // this is very costly operation
      s.erase(i - 1, 2);
      i -= 2;
      if (i == -1) i = 0;
    }
  }
  return s;
}

// Approach 2 [Stack Based Solution]
string removeDuplicates2(string s) {
  int n = s.length(), i;
  string ans;

  for (i = 0; i < n - 1; ++i) {
    if (s.at(i) != s.at(i + 1))
      if (!ans.empty() and ans.back() == s.at(i))
        ans.pop_back();
      else
        ans.push_back(s.at(i));
    else
      i++;
  }

  if (i == n - 1)
    if (!ans.empty() and ans.back() == s.at(i))
      ans.pop_back();
    else
      ans.push_back(s.at(i));

  return ans;
}

// Approach [Better Stack Based Solution]
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
string removeDuplicates2(string s) {
  string res = "";
  for (const char& c : s)
    if (res.size() and c == res.back())
      res.pop_back();
    else
      res.push_back(c);
  return res;
}

// Approach 3 [Two's Pointer Approach]
string removeDuplicates3(string s) {
  int n = s.length(), i, index = -1;

  for (i = 0; i < n - 1; ++i) {
    if (s.at(i) != s.at(i + 1))
      if (index >= 0 and s.at(index) == s.at(i))
        index--;
      else
        s.at(++index) = s.at(i);
    else
      i++;
  }

  if (i == n - 1)
    if (index >= 0 and s.at(index) == s.at(i))
      index--;
    else
      s.at(++index) = s.at(i);

  return s.substr(0, index + 1);
}

// Approach 4 [Better Two's Pointer Approach]
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
string removeDuplicates4(string s) {
  int i = 0, n = s.length();
  for (int j = 0; j < n; ++j, ++i) {
    s.at(i) = s.at(j);
    if (i > 0 and s.at(i - 1) == s.at(i)) i -= 2;
  }
  return s.substr(0, i);
}

int main(int argc, char const* argv[]) {
  cout << removeDuplicates3("azxxzy") << endl;
  return 0;
}
