// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

#include <bits/stdc++.h>

using namespace std;

// approach 1 - O(n) [TC] and O(n) [SC] - using 2 extra queues
void interLeaveQueue(queue<int>& q) {
  queue<int> q1;
  queue<int> q2;
  int half_size = q.size() / 2;

  for (int i = 0; i < half_size; ++i) {
    q1.push(q.front());
    q.pop();
  }

  for (int i = 0; i < half_size; ++i) {
    q2.push(q.front());
    q.pop();
  }

  for (int i = 0; i < half_size * 2; ++i) {
    if (i % 2) {
      q.push(q2.front());
      q2.pop();
    } else {
      q.push(q1.front());
      q1.pop();
    }
  }
}

// approach 2 - using single queue
void interLeaveQueue(queue<int>& q) {
  queue<int> temp;
  int size = q.size();

  for (int i = 0; i < size / 2; ++i) {
    temp.push(q.front());
    q.pop();
  }

  while (!temp.empty()) {
    q.push(temp.front());
    temp.pop();
    q.push(q.front());
    q.pop();
  }
}

// approach 3 - using single stack
void interLeaveQueue(queue<int>& q) {
  stack<int> s;
  int size = q.size();

  // queue - 1 2 3 4 5 6
  // stack -

  for (int i = 0; i < size / 2; ++i) {
    s.push(q.front());
    q.pop();
  }

  // queue - 4 5 6
  // stack - 3 (top) 2 1

  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }

  // queue - 4 5 6 3 2 1
  // stack -

  for (int i = 0; i < size / 2; ++i) {
    q.push(q.front());
    q.pop();
  }

  // queue - 3 2 1 4 5 6
  // stack -

  for (int i = 0; i < size / 2; ++i) {
    s.push(q.front());
    q.pop();
  }

  // queue - 4 5 6
  // stack - 1 2 3

  while (!s.empty()) {
    q.push(s.top());
    s.pop();
    q.push(q.front());
    q.pop();
  }
}