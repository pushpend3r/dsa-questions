// https://practice.geeksforgeeks.org/problems/sum-of-array-elements2502/1

#include <bits/stdc++.h>

using namespace std;

int sumElement(int arr[], int n) {
  if (n == 0) return 0;
  if (n == 1) return arr[0];
  return arr[0] + sumElement(arr + 1, --n);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
