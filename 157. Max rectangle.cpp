// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> prevSmallerElementIndex(vector<int>& arr) {
  int n = arr.size();

  vector<int> ans(n);

  stack<int> s;
  s.push(-1);

  for (int i = 0; i < n; ++i) {
    int num = arr[i];
    while (s.top() != -1 and arr[s.top()] >= num) s.pop();
    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

vector<int> nextSmallerElementIndex(vector<int>& arr) {
  int n = arr.size();

  vector<int> ans(n);

  stack<int> s;
  s.push(n);

  for (int i = n - 1; i >= 0; --i) {
    int num = arr[i];
    while (s.top() != n and arr[s.top()] >= num) s.pop();
    ans[i] = s.top();
    s.push(i);
  }

  return ans;
}

int largestRectangleArea(vector<int>& heights) {
  int ans = INT_MIN;
  int n = heights.size();

  vector<int> prev = prevSmallerElementIndex(heights);
  vector<int> next = nextSmallerElementIndex(heights);

  for (int i = 0; i < n; ++i) {
    int height = heights[i];
    int breadth = next[i] - prev[i] - 1;

    ans = max(ans, height * breadth);
  }

  return ans;
}

int maxArea(int M[MAX][MAX], int n, int m) {
  // copying first row
  vector<int> row(m);

  for (int i = 0; i < m; ++i) row[i] = M[0][i];

  int ans = largestRectangleArea(row);

  for (int i = 1; i < n; ++i) {
    int index = 0;
    for (int j = 0; j < m; ++j) {
      row[index] = M[i][j] ? row[index] + 1 : 0;
      index++;
    }
    ans = max(ans, largestRectangleArea(row));
  }

  return ans;
}
