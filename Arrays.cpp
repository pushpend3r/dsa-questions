#include <bits/stdc++.h>

using namespace std;

void print(int *arr, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) printf("%d ", *((arr + i * n) + j));
    cout << endl;
  }
  cout << endl;
}

void jaggedArrays() {
  int r1[] = {1, 2, 3};
  int r2[] = {4, 5};
  int size[] = {3, 2};

  int *jagged[] = {r1, r2};
  int rows = 2;

  for (int i = 0; i < rows; ++i) {
    int *ptr = jagged[i];
    for (int j = 0; j < size[i]; ++j) {
      cout << *ptr << " ";
      ptr++;
    }
    cout << endl;
  }

  // -----------------
  int **jagged2 = new int *[2];
  int jagged2Size[] = {3, 2};

  for (int i = 0; i < 2; ++i) {
    jagged2[i] = new int[jagged2Size[i]];
  }

  for (int i = 0; i < 2; ++i) {
    int *ptr = jagged2[i];
    for (int j = 0; j < jagged2Size[i]; ++j) {
      *ptr = 12;
      ptr++;
    }
  }

  for (int i = 0; i < 2; ++i) {
    int *ptr = jagged2[i];
    for (int j = 0; j < jagged2Size[i]; ++j) {
      cout << *ptr << " ";
      ptr++;
    }
    cout << endl;
  }

  for (int i = 0; i < 2; ++i) {
    delete[] jagged2[i];
  }
  delete[] jagged2;
}

int main() {
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int m = 3, n = 3;

  // We can also use "print(&arr[0][0], m, n);"
  print((int *)arr, m, n);
  jaggedArrays();
  return 0;
}
