// https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172

#include <bits/stdc++.h>

using namespace std;

// My Approach
string replaceSpaces(string &str) {
  string ans;
  for (const auto &i : str)
    if (i == ' ')
      ans.insert(ans.length(), "@40");
    else
      ans.push_back(i);

  return ans;
}

// Approach 2
string replaceSpaces2(string &str) {
  for (int i = 0; i < str.length(); ++i)
    if (str.at(i) == ' ') str.replace(i, 1, "@40");

  return str;
}

int main(int argc, char const *argv[]) {
  string name = "coding ninjas is a coding platform";
  replaceSpaces2(name);
  cout << name << endl;
  return 0;
}
