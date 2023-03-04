// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908

#include <bits/stdc++.h>

using namespace std;

class Queue {
 private:
  int arr[100001];
  int qfront = 0;  // point to front element index
  int rear = 0;    // point to free rear element index
  int size = 100001;

 public:
  bool isEmpty() { return qfront == rear; }

  void enqueue(int data) {
    if (rear == size) return;
    arr[rear++] = data;
  }

  int dequeue() {
    if (isEmpty()) return -1;
    int frontData = arr[qfront++];
    if (qfront == rear) qfront = rear = 0;
    return frontData;
  }

  int front() {
    if (isEmpty()) return -1;
    return arr[qfront];
  }
};