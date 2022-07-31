// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include <bits/stdc++.h>
#define ROW 3
#define COL 10

using namespace std;

// below solution only can be use where we want maximum area of a **square** sub
// matrix
int maxArea(int M[ROW][COL], int n, int m) {
  int ans = 0;
  for (int row = 1; row < n; row++) {
    for (int col = 1; col < m; col++) {
      if (!M[row][col]) continue;
      M[row][col] +=
          min({M[row][col - 1], M[row - 1][col], M[row - 1][col - 1]});
      ans = max(ans, M[row][col] * 2);
    }
  }
  return ans;
}

// -----------

int getMaximumAreaByRow2(int M[ROW][COL], int rowIndex, int m) {
  int ans = 0;
  vector<int> prevSmall, nextSmall;
  bool flag;
  for (int col = 0; col < m; col++) {
    flag = false;
    for (int j = col - 1; j >= 0; --j)
      if (M[rowIndex][j] < M[rowIndex][col]) {
        prevSmall.push_back(j);
        flag = true;
        break;
      }
    if (!flag) prevSmall.push_back(-1);

    flag = false;
    for (int j = col + 1; j < m; ++j)
      if (M[rowIndex][j] < M[rowIndex][col]) {
        nextSmall.push_back(j);
        flag = true;
        break;
      }
    if (!flag) nextSmall.push_back(m);
  }

  for (int i = 0; i < m; ++i)
    ans = max(ans, (nextSmall.at(i) - prevSmall.at(i) - 1) * M[rowIndex][i]);

  return ans;
}

// Approach 2 (getting TLE 😔) above func is very costly here
int maxArea2(int M[ROW][COL], int n, int m) {
  int ans = getMaximumAreaByRow2(M, 0, m);
  for (int row = 1; row < n; row++) {
    for (int col = 0; col < m; col++)
      if (M[row][col]) M[row][col] += M[row - 1][col];
    ans = max(ans, getMaximumAreaByRow2(M, row, m));
  }
  return ans;
}

// ---------------------

int getMaximumAreaByRow(int M[ROW][COL], int rowIndex, int m) {
  vector<int> prevSmall, nextSmall;
  stack<int> s;
  int col = 0;

  while (col < m) {
    while (!s.empty() and M[rowIndex][s.top()] >= M[rowIndex][col]) s.pop();
    if (s.empty()) {
      prevSmall.push_back(-1);
    } else {
      prevSmall.push_back(s.top());
    }
    s.push(col);
    col++;
  }
  while (!s.empty()) s.pop();
  col = m - 1;
  while (col >= 0) {
    while (!s.empty() and M[rowIndex][s.top()] >= M[rowIndex][col]) s.pop();
    if (s.empty()) {
      nextSmall.push_back(m);
    } else {
      nextSmall.push_back(s.top());
    }
    s.push(col);
    col--;
  }

  reverse(nextSmall.begin(), nextSmall.end());

  int ans = 0;
  for (int i = 0; i < m; ++i)
    ans =
        max(ans, abs((nextSmall.at(i) - prevSmall.at(i) - 1) * M[rowIndex][i]));

  return ans;
}

// Approach 3 (using stacks)
// https://www.youtube.com/watch?v=_RtghJnM1Qo
int maxArea3(int M[ROW][COL], int n, int m) {
  int ans = getMaximumAreaByRow(M, 0, m);
  for (int row = 1; row < n; row++) {
    for (int col = 0; col < m; col++)
      if (M[row][col]) M[row][col] += M[row - 1][col];
    ans = max(ans, getMaximumAreaByRow(M, row, m));
  }
  return ans;
}

int main(int argc, char const* argv[]) {
  int M[ROW][COL] = {{0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                     {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                     {0, 0, 1, 0, 0, 0, 1, 0, 1, 1}};
  cout << maxArea3(M, ROW, COL) << endl;
  // cout << getMaxArea({6, 2, 5, 4, 5, 1, 6}, 7) << endl;
  return 0;
}
