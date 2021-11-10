#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B;
  cin >> A >> B;

  string a, b;
  a = "A:", b = "B:";
  rep(i, A) {
      a += "]";
  }
  rep(i, B) {
      b += "]";
  }
  cout << a << endl;
  cout << b << endl;
}

