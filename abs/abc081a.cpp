#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int s;
    cin >> s;

    int c = 0;
    rep(i, 3) {
        c += s % 10;
        s /= 10;
    }

    cout << c << endl;
}