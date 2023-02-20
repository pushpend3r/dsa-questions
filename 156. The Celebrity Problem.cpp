// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <bits/stdc++.h>

using namespace std;

// approach 1 - T.C - O(n*n)
int celebrity(vector<vector<int> >& M, int n) {
  for (int i = 0; i < n; ++i) {
    bool isHeACelebrity = true;
    bool isEveryBodyKnowsHim = true;

    for (auto& value : M[i]) {
      if (value) {
        isHeACelebrity = false;
        break;
      }
    }

    if (isHeACelebrity == false) continue;

    // assuming he knows himself
    M[i][i] = true;

    for (auto& row : M) {
      if (!row[i]) {
        isEveryBodyKnowsHim = false;
        break;
      }
    }

    if (isEveryBodyKnowsHim and isHeACelebrity) return i;
  }

  return -1;
}

// Approach 2 - T.C - O(N), S.C - O(N) for stack
int celebrity(vector<vector<int> >& M, int n) {
  stack<int> s;
  for (int i = 0; i < n; ++i) s.push(i);

  // finding potential celebrity
  while (s.size() > 1) {
    int a = s.top();
    s.pop();

    int b = s.top();
    s.pop();

    // a knows b and b doesn't know a, so might be b is a celebrity
    if (M[a][b] and !M[b][a]) s.push(b);
    // b knows a and a doesn't know b, so might be b is a celebrity
    else if (M[b][a] and !M[a][b])
      s.push(a);
  }

  if (s.empty()) return -1;

  int top = s.top();
  s.pop();

  for (int i = 0; i < n; ++i)
    if ((i != top and !M[i][top]) or M[top][i]) return -1;

  return top;
}

// Approach 3 - T.C - O(N), S.C - O(1)
int celebrity(vector<vector<int> >& M, int n) {
  int potential_celebrity = 0;

  for (int i = 1; i < n; ++i) {
    if (M[potential_celebrity][i]) {
      potential_celebrity = i;
    }
  }

  for (int i = 0; i < n; ++i)
    if ((i != potential_celebrity and !M[i][potential_celebrity]) or
        M[potential_celebrity][i])
      return -1;

  return potential_celebrity;
}

// Approach 4 - T.C - O(N), S.C - O(1)
int celebrity(vector<vector<int> >& M, int n) {
  int start = 0, end = n - 1;

  while (start < end) M[start][end] ? start++ : end--;

  int potential_celebrity = start;

  for (int i = 0; i < n; ++i)
    if ((i != potential_celebrity and !M[i][potential_celebrity]) or
        M[potential_celebrity][i])
      return -1;

  return potential_celebrity;
}