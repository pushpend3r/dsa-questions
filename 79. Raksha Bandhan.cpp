// https://www.codingninjas.com/codestudio/problems/raksha-bandhan_2179752

#include <bits/stdc++.h>

using namespace std;

int rakshaBandhan(vector<int> arr, int n) {
  sort(arr.begin(), arr.end(), [](int &a, int &b) { return a > b; });

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr.at(i);
    if (sum <= 0) return i;
  }

  return n;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {3, -3};
  cout << rakshaBandhan(arr, arr.size()) << endl;
  return 0;
}
