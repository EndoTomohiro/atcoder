#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int d = 0;
    rep(i, a+1)rep(j, b+1)rep(k, c+1) {
        if (x == 500 * i + 100 * j + 50 * k) d++;
    }

    cout << d << endl;
}