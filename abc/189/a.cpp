#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    string c;
    cin >> c;

    if (c[0] == c[1] && c[0] == c[2]) cout << "Won" << endl;
    else cout << "Lost" << endl;
}