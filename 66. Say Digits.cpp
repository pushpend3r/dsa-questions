#include <bits/stdc++.h>

using namespace std;

string num(int n) {
  switch (n) {
    case 0:
      return "Zero";
    case 1:
      return "One";
    case 2:
      return "Two";
    case 3:
      return "Three";
    case 4:
      return "Four";
    case 5:
      return "Five";
    case 6:
      return "Six";
    case 7:
      return "Seven";
    case 8:
      return "Eight";
    case 9:
      return "Nine";
  }

  return "";
}

void SayDigits(int n) {
  if (n == 0) return;
  SayDigits(n / 10);
  cout << num(n % 10) << " ";
}

int main(int argc, char const *argv[]) {
  SayDigits(121212);
  cout << endl;
  return 0;
}
