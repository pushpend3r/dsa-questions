// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>

using namespace std;

class MinStack {
 private:
  stack<long long> s;
  long long min;

 public:
  void push(int val) {
    if (s.empty()) {
      s.push(val);
      min = val;
      return;
    }

    if (val >= min) {
      s.push(val);
      return;
    }
    /*
    here if val < current_min, then we will encode a new number and push it to
    stack.
    *** val < current_min
    *** val - current_min < 0
    *** val - current_min + val < 0 + val
    *** 2 * val - current_min < val
    *** 2 * val - current_min is the encoding value, we check this as a flag
    */
    /* check strivers video on this he explained it better*/
    /* https://www.youtube.com/watch?v=V09NfaGf2ao */
    s.push(2 * 1ll * val - min);
    min = val;
  }

  void pop() {
    long long top = s.top();
    s.pop();

    if (top < min) min = 2 * min - top;
  }

  int top() {
    if (s.top() < min)
      return min;
    else
      return s.top();
  }

  int getMin() { return min; }
};