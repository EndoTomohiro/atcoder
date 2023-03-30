#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        if (a > b) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }

    else {
        if (a >= b) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }
}