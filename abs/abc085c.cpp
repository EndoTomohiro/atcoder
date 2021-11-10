#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, y;
    cin >> n >> y;

    bool ok = false;
    rep(i, n+1) {
        bool oki = false;
        rep(j, n+1-i) {
            if (10000 * i + 5000 * j + 1000 * (n - i - j) == y) {
                ok = true;
                oki = true;
                cout << i << ' ' << j << ' ' << n - i - j << endl;
                break;
            }
        }
        if (oki) break;
    }

    if (!ok) cout << "-1 -1 -1" << endl;
}