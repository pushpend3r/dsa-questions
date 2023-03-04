//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
  int petrol;
  int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
 public:
  // Function to find starting point where the truck can start to get through
  // the complete circle without exhausting its petrol in between.
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
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++) cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
  }
}

// } Driver Code Ends