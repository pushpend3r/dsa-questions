// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

#include <bits/stdc++.h>

using namespace std;

// approach 1
class QueueStack {
 private:
  queue<int> q1;
  queue<int> q2;

 public:
  // O(n)
  void push(int x) {
    q2.push(x);

    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    swap(q1, q2);
  }

  // O(1)
  int pop() {
    if (q1.empty()) return -1;
    int poppedElement = q1.front();
    q1.pop();
    return poppedElement;
  }
};

// approach 2
class QueueStack {
 private:
  queue<int> q1;
  queue<int> q2;

 public:
  // O(1)
  void push(int x) { q1.push(x); }

  // O(n)
  int pop() {
    if (q1.empty()) return -1;
    while (q1.size() > 1) {
      q2.push(q1.front());
      q1.pop();
    }
    int poppedElement = q1.front();
    q1.pop();
    swap(q1, q2);
    return poppedElement;
  }
};

// approach 3 - using 1 queue
class QueueStack {
 private:
  queue<int> q1;

 public:
  // O(1)
  void push(int x) { q1.push(x); }

  // O(n)
  int pop() {
    if (q1.empty()) return -1;

    int n = q1.size() - 1;

    for (int i = 0; i < n; ++i) {
      q1.push(q1.front());
      q1.pop();
    }

    int poppedElement = q1.front();
    q1.pop();

    return poppedElement;
  }
};