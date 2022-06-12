// https://leetcode.com/problems/unique-number-of-occurrences/

#include <bits/stdc++.h>

using namespace std;

bool uniqueOccurences(vector<int> &arr)
{
  int n = arr.size() - 1;
  int occurences[2001] = {0};
  for (int i = 0; i <= n; ++i)
  {
    if (arr[i] < 0)
    {
      ++occurences[1000 - arr[i]];
    }
    else
    {
      ++occurences[arr[i]];
    }
  }

  sort(occurences, occurences + 2001);

  for (int i = 2000; i > 0; --i)
  {
    if (occurences[i] == 0)
    {
      break;
    }
    else if (occurences[i] == occurences[i - 1])
    {
      return false;
    }
  }

  return true;
}

// Approach 2 (using STL)
// refer - https://leetcode.com/problems/unique-number-of-occurrences/discuss/392840/C%2B%2B-2-approaches
bool uniqueOccurrences(vector<int> &arr)
{
  unordered_map<int, int> m;
  unordered_set<int> s;
  for (auto n : arr)
    ++m[n];
  for (auto &p : m)
    s.insert(p.second);
  return m.size() == s.size();
}

int main(void)
{
  vector<int> arr = {1, 2};
  cout << uniqueOccurences(arr) << endl;
}