// https://leetcode.com/problems/string-compression/

#include <bits/stdc++.h>

using namespace std;

void appendCount(vector<char> &c, int &index, int &count) {
  int i = index;
  while (count) {
    c.at(++index) = count % 10 + '0';
    count /= 10;
  }
  reverse(c.begin() + i + 1, c.begin() + index + 1);
}

// My Approach
int compress(vector<char> &chars) {
  int index = 0, count = 1, n = chars.size();
  for (int i = 1; i < n; ++i) {
    if (chars.at(index) == chars.at(i))
      count++;
    else {
      if (count > 1) appendCount(chars, index, count);
      chars.at(++index) = chars.at(i);
      count = 1;
    }
  }

  if (count > 1) appendCount(chars, index, count);

  // although we don't have to resize it by ourself
  chars.resize(index + 1);

  return index + 1;
}

// Approach 2 (less code then one)
int compress(vector<char> &chars) {
  int index = 0, count = 1, n = chars.size();
  for (int i = 1; i < n; ++i) {
    if (chars.at(index) == chars.at(i))
      count++;
    else {
      if (count > 1)
        for (const char &i : to_string(count)) chars.at(++index) = i;
      chars.at(++index) = chars.at(i);
      count = 1;
    }
  }

  if (count > 1)
    for (const char &i : to_string(count)) chars.at(++index) = i;

  return index + 1;
}

// Approach 3 (love babber's)
int compress(vector<char> &chars) {
  // i = i'th character whose count we finding
  // j = i + 1;
  // n = vector length
  // index = place to store the value
  // count = i'th character count
  int i = 0, j, n = chars.size(), index = 0, count;
  while (i < n) {
    j = i + 1;
    // finding the next different character's index
    while (j < n and chars.at(j) == chars.at(i)) j++;
    chars.at(index++) = chars.at(i);
    count = j - i;
    if (count > 1)
      for (const char &i : to_string(count)) chars.at(index++) = i;
    i = j;
  }
  return index;
}

int main(int argc, char const *argv[]) {
  vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                        'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                        'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'c'};
  cout << compress(chars) << endl;
  for (const char &i : chars) cout << i;
  cout << endl;
  return 0;
}
