#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  vector<int> x(3);
  x[0] = A;
  x[1] = B;
  x[2] = C;
  sort(x.begin(), x.end());

  cout << x[2] - x[0] << endl;
}

