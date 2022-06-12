// https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028

#include <bits/stdc++.h>

using namespace std;

// Approach 1 (BEST)
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
  /*
  arr = Array to be work upon
  n = size of array
  K = sum whose distinct triplets we have to find out
  */

  sort(arr.begin(), arr.end());

  vector<vector<int>> triplets;

  for (int i = 0; i < n; ++i)
  {
    int target = K - arr[i];
    int front = i + 1;
    int back = n - 1;

    while (front < back)
    {
      int currentFront = arr[front], currentBack = arr[back];
      int currentSum = currentFront + currentBack;
      if (currentSum == target)
      {
        vector<int> triplet;
        triplet.push_back(arr[i]);
        triplet.push_back(currentFront);
        triplet.push_back(currentBack);

        triplets.push_back(triplet);

        // Move front forward to next distinct number, make sure to not exceed from back 😋.
        while (front < back && currentFront == arr[front])
          front++;

        // Move back backward to next distinct number
        while (front < back && currentBack == arr[back])
          back--;
      }
      else if (currentSum < target)
      {
        front++;
      }
      else
      {
        back--;
      }
    }

    // Moving i to next distinct number
    while (i + 1 < n && arr[i] == arr[i + 1])
      i++;
  }

  return triplets;
}

// Approach 2 (Brute Force)
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

  // Set to keep the track of visited triplets.
  set<vector<int>> visited;
  vector<vector<int>> ans;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        // If we find a valid triplet.
        if (arr[i] + arr[j] + arr[k] == K)
        {
          vector<int> triplet;
          triplet.push_back(arr[i]);
          triplet.push_back(arr[j]);
          triplet.push_back(arr[k]);

          // Sorting the triplet track distinct triplets.
          sort(triplet.begin(), triplet.end());
          if (visited.find(triplet) == visited.end())
          {
            ans.push_back(triplet);
            visited.insert(triplet);
          }
        }
      }
    }
  }

  return ans;
}

int main(void)
{
}