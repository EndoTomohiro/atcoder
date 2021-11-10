#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  int x = 0;
  for (int i = 0; i < data.size() - 1; i++) {
    if (data[i] == data[i+1]) {
      x++;
      cout << "YES" << endl;
      break;
    }
  }

  if (x == 0) cout << "NO" << endl;
}
