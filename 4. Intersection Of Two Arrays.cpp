// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

#include <bits/stdc++.h>

using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
  vector<int> ans;

  int i = 0, j = 0;

  while (i < arr1.size() && j < arr2.size())
  {
    if (arr1[i] == arr2[j])
    {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return ans;
}

int main()
{
}