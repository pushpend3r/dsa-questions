// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

#include <bits/stdc++.h>

using namespace std;

// approach 1
class StackQueue {
 private:
  stack<int> s1;
  stack<int> s2;

 public:
  // O(1)
  void push(int x) { s1.push(x); }
  // O(N)
  int pop() {
    // if stack is empty
    if (s1.empty()) return -1;

    // pop all element from s1 and push to s2 except last s1 element
    while (s1.size() > 1) {
      s2.push(s1.top());
      s1.pop();
    }

    int poppedElement = s1.top();
    s1.pop();

    // move back element from s2 to s1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }

    return poppedElement;
  }
};

// approach 2
class StackQueue {
 private:
  stack<int> s1;
  stack<int> s2;

 public:
  // O(N)
  void push(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(x);

    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  // O(1)
  int pop() {
    // if stack is empty
    if (s1.empty()) return -1;

    int poppedElement = s1.top();
    s1.pop();

    return poppedElement;
  }
};