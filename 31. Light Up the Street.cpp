// https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/problems/14751

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int target) {
  if (start >= arr.size()) return -1;
  int ans = -1, mid;

  while (start <= end) {
    mid = start + (end - start) / 2;
    if (arr.at(mid) <= target) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

// My Approach
int LightUptheStreet(int streetLength, int lightAvail, int range,
                     vector<int> checkpoints) {
  int cp = binarySearch(checkpoints, 0, lightAvail - 1, range + 1);

  if (cp == -1) return -1;

  int ans = 1;

  while (checkpoints.at(cp) + range < streetLength) {
    cp = binarySearch(checkpoints, cp + 1, lightAvail - 1,
                      checkpoints.at(cp) + (range * 2) + 1);

    if (cp == -1) return -1;
    ans++;
  }

  return ans;
}

// Approach 2
int LightUptheStreet2(int streetLength, int m, int range, vector<int> cps) {
  // gap between indices = value of ith + range + range + value of (i + 1)th

  // max = previous cp cover range to right
  // cp = last actual placed cp cover range to right
  int max = 0, cp = 0, ans = 0;

  for (const int &i : cps) {
    if (i - range - 1 > cp) {
      // gap between the previous indices reachable range is higher than it
      // should be
      if (i - range - 1 > max) {
        ans = -1;
        break;
      }
      ans++;
      cp = max;
    }

    // ith indice's cover range
    max = i + range;
  }

  if (cp < streetLength) {
    if (max < streetLength)
      ans = -1;
    else
      ans++;
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  cout << LightUptheStreet2(7, 3, 4, {2, 4, 5}) << endl;
  return 0;
}
