// https://practice.geeksforgeeks.org/problems/stack-permutations/1

#include <bits/stdc++.h>

using namespace std;

// approach 1
int isStackPermutation(int N, vector<int> &A, vector<int> &B) {
  stack<int> s;
  int index = 0;
  int i = 0;

  while (i < N) {
    // does stack top have element we want
    if (!s.empty() and s.top() == B[index]) {
      s.pop();
      index++;
    }
    // does array A ith index have element we want
    else if (A[i] == B[index]) {
      index++;
      i++;
    }
    // look like we need to go further
    else {
      s.push(A[i]);
      i++;
    }
  }

  // does stack top have element we want
  while (!s.empty() and s.top() == B[index]) {
    s.pop();
    index++;
  }

  return index == N ? 1 : 0;
}

// approach 2 - better than approach 1
int isStackPermutation(int N, vector<int> &A, vector<int> &B) {
  stack<int> s;
  int index = 0;
  int i = 0;

  while (i < N and index < N) {
    s.push(A[i]);
    i++;
    // does stack top have element we want
    while (!s.empty() and s.top() == B[index]) {
      s.pop();
      index++;
    }
  }

  return index == N;
}