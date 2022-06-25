// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-l/problems/16513

#include <bits/stdc++.h>

using namespace std;

void setChar(vector<char> &row, char ch, int c, int pos, int s) {
  for (int i = 0; i < c; ++i) row.at((i * s * 2) + pos) = ch;
}

// it think shorten the code but not goona, 'cuz i need to learn more concepts.
void printTheDiamond(int r, int c, int s) {
  vector<vector<char>> row(s * 2, vector<char>(c * s * 2));

  for (int i = 0; i < r; ++i) {
    int temp_S = s;

    // first half vertically
    for (int i = 0; i < s; ++i) {
      temp_S--;
      for (int j = 0; j < s; ++j) {
        if (j == temp_S) {
          setChar(row.at(i), '/', c, j, s);
          setChar(row.at(i), '\\', c, (s * 2) - j - 1, s);
        } else if (j < temp_S) {
          setChar(row.at(i), 'e', c, j, s);
          setChar(row.at(i), 'e', c, (s * 2) - j - 1, s);
        } else {
          setChar(row.at(i), 'o', c, j, s);
          setChar(row.at(i), 'o', c, (s * 2) - j - 1, s);
        }
      }
    }

    // next half vertically
    temp_S--;
    for (int i = 0; i < s; ++i) {
      temp_S++;
      for (int j = 0; j < s; ++j) {
        if (j == temp_S) {
          setChar(row.at(i + s), '\\', c, j, s);
          setChar(row.at(i + s), '/', c, (s * 2) - j - 1, s);
        } else if (j < temp_S) {
          setChar(row.at(i + s), 'e', c, j, s);
          setChar(row.at(i + s), 'e', c, (s * 2) - j - 1, s);
        } else {
          setChar(row.at(i + s), 'o', c, j, s);
          setChar(row.at(i + s), 'o', c, (s * 2) - j - 1, s);
        }
      }
    }

    // printing
    for (const auto &i : row) {
      for (const auto &j : i) cout << j;
      cout << endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  int t, r, c, s;
  cin >> t;
  while (t--) {
    cin >> r >> c >> s;
    printTheDiamond(r, c, s);
  }
  return 0;
}
