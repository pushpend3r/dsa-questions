// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <bits/stdc++.h>

using namespace std;

struct petrolPump {
  int petrol;
  int distance;
};

bool isPossible(petrolPump p[], int n, int index) {
  int i = index;
  int availablePetrol = 0;
  do {
    availablePetrol += p[i].petrol;
    if (availablePetrol < p[i].distance) return false;
    availablePetrol -= p[i].distance;
    i = (i + 1) % n;
  } while (i != index);

  return true;
}

// approach 1 - O(n * n) [TC] and O(1) [SC]
int tour(petrolPump p[], int n) {
  for (int i = 0; i < n; ++i)
    if (isPossible(p, n, i)) return i;
  return -1;
}

// approach 2
int tour(petrolPump p[], int n) {
  int start = 0;
  int additionalPetrolRequired = 0;
  int petrol = 0;

  for (int i = 0; i < n; ++i) {
    petrol += p[i].petrol - p[i].distance;
    if (petrol < 0) {
      additionalPetrolRequired -= petrol;
      start = i + 1;
      petrol = 0;
    }
  }

  if (additionalPetrolRequired - petrol > 0) return -1;
  return start;
}

// approach 3 - not better than approach 2 still bit better than approach 1
int tour(petrolPump p[], int n) {
  int start = 0;
  int rear = 0;
  int petrol = 0;

  while (1) {
    petrol += p[rear].petrol - p[rear].distance;
    rear = (rear + 1) % n;

    if (petrol < 0) {
      if (start == n - 1) return -1;
      if (start < rear) {
        start = rear;
      } else {
        start++;
        rear = start;
      }
      petrol = 0;
      continue;
    }

    // circle been completed.
    if (rear == start) break;
  }

  return start;
}
