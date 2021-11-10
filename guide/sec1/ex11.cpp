#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  int x = 0;
  cin >> N >> A;

  for (int i = 0; i < N; i++) {
      string op;
      int b;
      cin >> op >> b;
      if (x == 0) {
          if (op == "/" && b == 0) {
              cout << "error" << endl;
              x = 1;
          }
          else {
              cout << i + 1 << ":";
              if (op == "+") {
                  A += b;
                  cout << A << endl;
              }
              else if (op == "-") {
                  A -= b;
                  cout << A << endl;
              }
              else if (op == "*") {
                  A *= b;
                  cout << A << endl;
              }
              else {
                  A /= b;
                  cout << A << endl;
              }
          }
      }
  }
}

