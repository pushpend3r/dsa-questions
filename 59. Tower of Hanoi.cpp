// https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380918

#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int start, int end, vector<vector<int>> &moves) {
  if (n == 1) {
    moves.push_back({start, end});
    return;
  }
  // finds rod other than start and end e.g
  // Total 3 Rods are there 1, 2, 3
  // so start and end can be {1, 2}, {1,3} ,{2,3}
  // 6 - (1+2) = 3
  // 6 - (1+3) = 2
  // 6 - (2+3) = 1
  int other = 6 - (start + end);

  // move n - 1 to other rod
  hanoi(n - 1, start, other, moves);
  // now move nth disk to end
  moves.push_back({start, end});
  // move back the top n - 1 disks to end
  hanoi(n - 1, other, end);
}

vector<vector<int>> towerOfHanoi(int n) {
  vector<vector<int>> moves;
  hanoi(n, 1, 3, moves);
  return moves;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
