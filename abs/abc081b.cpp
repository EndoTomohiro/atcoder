#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int c = 100000000;
    rep(i, n) {
        int c1 = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            c1++;
        }
        c = min(c, c1);
    }

    cout << c << endl;
}