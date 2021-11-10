#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  // パターン1
  if (p == 1) {
    int N, price;
    cin >> N >> price;
    cout << price * N << endl;
  }

  // パターン2
  if (p == 2) {
    string text;
    int N, price;
    cin >> text >> N >> price;
    cout << text << "!" << endl;
    cout << price * N << endl;
  }
}

