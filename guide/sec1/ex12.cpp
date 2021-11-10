#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int x = 1;
  for (int i; i < S.size() / 2; i++) {
      if (S.at(2*i+1) == '+') x += 1;
      else x -= 1;
  }
  cout << x << endl;
}

