// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271

#include <bits/stdc++.h>

using namespace std;

class NStack {
 private:
  // arr is the actual array, top keeps the indexes of all stacks top, next
  // stores the free spaces and next top element stack of stacks
  vector<int> arr, top, next;
  int freeSpaceIndex;

 public:
  // Initialize your data structure.
  NStack(int N, int S) : arr(S), top(N, -1), next(S), freeSpaceIndex(0) {
    // set next arr values
    for (int i = 0; i < S; ++i) next[i] = i + 1;
    next[S - 1] = -1;
  }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
  // stack, and false otherwise.
  bool push(int x, int m) {
    if (freeSpaceIndex == -1) return false;

    arr[freeSpaceIndex] = x;

    int nextFreeSpaceIndex = next[freeSpaceIndex];

    next[freeSpaceIndex] = top[m - 1];
    top[m - 1] = freeSpaceIndex;
    freeSpaceIndex = nextFreeSpaceIndex;
    return true;
  }

  // Pops top element from Mth Stack. Returns -1 if the stack is empty,
  // otherwise returns the popped element.
  int pop(int m) {
    if (top[m - 1] == -1) return -1;

    int topElementIndex = top[m - 1];
    int poppedElement = arr[topElementIndex];

    top[m - 1] = next[topElementIndex];

    // add topelement index to the free pool
    // think freespaceindex like a linked list
    next[topElementIndex] = freeSpaceIndex;
    freeSpaceIndex = topElementIndex;

    return poppedElement;
  }
};

int main(int argc, char const *argv[]) {
  auto s = new NStack(3, 6);
  return 0;
}
