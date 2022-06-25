// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-l/problems/15017

#include <bits/stdc++.h>

using namespace std;

long long threeWaySplit(int n, vector<int> arr) {
  long long possibleMaxSum = 0, start = 0, end = n - 1,
            startSum = arr.at(start), endSum = arr.at(end);

  while (start < end) {
    if (startSum == endSum) {
      possibleMaxSum = startSum;
      startSum += arr.at(++start);
    } else if (startSum < endSum)
      startSum += arr.at(++start);
    else
      endSum += arr.at(--end);
  }

  return possibleMaxSum;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {5, 2, 4, 1, 4};
  cout << threeWaySplit(arr.size(), arr) << endl;
  return 0;
}
