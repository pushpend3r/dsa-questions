// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>

using namespace std;

void reverse(queue<int> &q) {
  if (q.empty()) return;
  int front = q.front();
  q.pop();
  reverse(q);
  q.push(front);
}

// approach 1
queue<int> modifyQueue(queue<int> q, int k) {
  queue<int> temp_q;

  // get first k element
  while (k--) {
    temp_q.push(q.front());
    q.pop();
  }

  // reverse the rest elements
  reverse(q);

  // insert first-get elements back to queue
  while (!temp_q.empty()) {
    q.push(temp_q.front());
    temp_q.pop();
  }

  // reverse the queue again..
  reverse(q);
  return q;
}

// Approach 2
queue<int> modifyQueue(queue<int> q, int k) {
  stack<int> s;
  queue<int> ans;

  while (k--) {
    s.push(q.front());
    q.pop();
  }

  while (!s.empty()) {
    ans.push(s.top());
    s.pop();
  }

  while (!q.empty()) {
    ans.push(q.front());
    q.pop();
  }

  return ans;
}

// approach 3
queue<int> modifyQueue(queue<int> q, int k) {
  stack<int> s;
  int size = q.size();

  for (int i = 0; i < k; ++i) {
    s.push(q.front());
    q.pop();
  }

  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }

  while (size-- != k) {
    q.push(q.front());
    q.pop();
  }

  return q;
}