// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>

using namespace std;

// My Approach
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int pos1 = m - 1, pos2 = n - 1, pos = n + m - 1;

  while (pos2 >= 0 and pos1 >= 0) {
    if (nums1.at(pos1) <= nums2.at(pos2))
      nums1.at(pos) = nums2.at(pos2--);
    else
      nums1.at(pos) = nums1.at(pos1--);

    pos--;
  }

  while (pos2 != -1) nums1.at(pos--) = nums2.at(pos2--);
}

// Approach 2
// https://leetcode.com/problems/merge-sorted-array/discuss/29515/4ms-C++-solution-with-single-loop/1329671
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int pos1 = m - 1, pos2 = n - 1, pos = n + m - 1;

  while (pos2 >= 0) {
    if (pos1 >= 0 and nums1.at(pos1) > nums2.at(pos2))
      nums1.at(pos--) = nums1.at(pos1--);
    else
      nums1.at(pos--) = nums2.at(pos2--);
  }
}

int main(int argc, char const* argv[]) {
  vector<int> num1 = {0}, num2 = {1};
  merge(num1, 0, num2, 1);
  for (auto i : num1) cout << i << " ";
  cout << endl;
  return 0;
}
