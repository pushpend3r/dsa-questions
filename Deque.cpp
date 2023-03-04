// https://www.codingninjas.com/codestudio/problems/deque_1170059

#include <bits/stdc++.h>

using namespace std;

class Deque {
 private:
  int *arr;
  int front;
  int rear;
  int size;

 public:
  Deque(int n) {
    size = n;
    arr = new int[size];
    front = rear = -1;
  }

  bool pushFront(int x) {
    if (isFull()) return false;

    if (front == -1) {
      front = rear = 0;
    } else {
      front--;
      if (front == -1) front = size - 1;
    }

    arr[front] = x;
    return true;
  }

  bool pushRear(int x) {
    if (isFull()) return false;

    if (front == -1) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }

    arr[rear] = x;
    return true;
  }

  int popFront() {
    if (isEmpty()) return -1;
    int element = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % size;

    return element;
  }

  int popRear() {
    if (isEmpty()) return -1;
    int element = arr[rear];
    if (front == rear)
      front = rear = -1;
    else {
      rear--;
      if (rear == -1) rear = size - 1;
    }
    return element;
  }

  int getFront() { return isEmpty() ? -1 : arr[front]; }

  int getRear() { return isEmpty() ? -1 : arr[rear]; }

  bool isEmpty() { return front == -1; }

  bool isFull() {
    return (front == 0 and rear == size - 1) or (front == rear + 1);
  }
};