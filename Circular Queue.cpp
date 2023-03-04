// https://www.codingninjas.com/codestudio/problems/circular-queue_1170058

#include <bits/stdc++.h>

using namespace std;

class CircularQueue {
 private:
  int *arr;
  int front;
  int rear;
  int size;

 public:
  CircularQueue(int n) {
    size = n;
    arr = new int[size];
    front = rear = -1;
  }

  bool enqueue(int value) {
    // if queue is full
    if ((front == 0 and rear == size - 1) or (front == rear + 1)) return false;

    // queue is empty
    if (front == -1)
      front = rear = 0;
    else
      rear = (rear + 1) % size;

    arr[rear] = value;
    return true;
  }

  int dequeue() {
    // queue is empty
    if (front == -1) return -1;

    int frontElement = arr[front];

    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % size;

    return frontElement;
  }
};