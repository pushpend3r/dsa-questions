// https://www.codingninjas.com/codestudio/problems/n-queue-using-array_1170053

#include <bits/stdc++.h>

using namespace std;

class NQueue {
 private:
  int *arr;

  int *front;
  int *rear;
  int *next;

  int size;
  int freeSpaceIndex;

 public:
  NQueue(int n, int s) {
    size = s;

    arr = new int[size];
    next = new int[size];

    front = new int[n];
    for (int i = 0; i < n; ++i) front[i] = -1;

    rear = new int[n];
    for (int i = 0; i < n; ++i) rear[i] = -1;

    for (int i = 0; i < size; ++i) next[i] = i + 1;
    next[size - 1] = -1;

    freeSpaceIndex = 0;
  }

  bool enqueue(int x, int m) {
    m--;

    if (freeSpaceIndex == -1) return false;
    int nextFreeSpaceIndex = next[freeSpaceIndex];

    arr[freeSpaceIndex] = x;

    // queue is empty
    if (front[m] == -1) {
      front[m] = freeSpaceIndex;
    } else {
      next[rear[m]] = freeSpaceIndex;
    }

    next[freeSpaceIndex] = -1;
    rear[m] = freeSpaceIndex;

    freeSpaceIndex = nextFreeSpaceIndex;

    return true;
  }

  int dequeue(int m) {
    m--;

    // if queue is empty
    if (front[m] == -1) return -1;

    int frontElementIndex = front[m];
    int popElement = arr[frontElementIndex];

    // if queue has only one element..
    if (rear[m] == frontElementIndex) rear[m] = -1;

    // set front to 2nd element index
    front[m] = next[frontElementIndex];

    // add the popped element index to freepool
    next[frontElementIndex] = freeSpaceIndex;
    freeSpaceIndex = frontElementIndex;

    return popElement;
  }
};