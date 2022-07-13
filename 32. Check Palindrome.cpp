// https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633

#include <bits/stdc++.h>

using namespace std;

// alternative to tolower func
char toLowerCase(char ch) {
  if (ch >= 'a' && ch <= 'z') return ch;
  //  ch - 65 + 97 = ch + 32
  return ch - 'A' + 'a';
}

bool checkPalindrome(string s) {
  int start = 0, end = s.size() - 1;
  while (start < end) {
    char l_start = tolower(s.at(start));
    char l_end = tolower(s.at(end));

    // if l_start is not an alphabet and digits
    if (!(l_start >= '0' and l_start <= '9') and
        !(l_start >= 'a' and l_start <= 'z'))
      start++;
    // if l_end is not an alphabet and digits
    else if (!(l_end >= '0' and l_end <= '9') and
             !(l_end >= 'a' and l_end <= 'z'))
      end--;
    // if they are not equal
    else if (l_start != l_end)
      return false;
    else
      start++, end--;
  }

  return true;
}

bool checkPalindrome(string s) {
  int start = 0, end = s.size() - 1;
  while (start < end) {
    if (!isalnum(s.at(start)))
      start++;
    else if (!isalnum(s.at(end)))
      end--;
    else if (tolower(s.at(start)) != tolower(s.at(end)))
      return false;
    else
      start++, end--;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
