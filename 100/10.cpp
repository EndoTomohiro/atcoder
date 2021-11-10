#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;

    int suma = 0;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        suma+= a[i];
    }

    int q;
    cin >> q;

    vector<int> m(q);
    rep(i, q) cin >> m[i];

    rep(i, q) {

        if (m[i] > suma) {
            puts("no");
            continue;
        }
        
        bool ok = false;

        rep(j, 1 << n) {
            bitset<20> bit(j);
            int sum = 0;

            rep(k, n) {
                if (bit.test(k)) sum += a[k];
            }

            if (sum == m[i]) {
                ok = true;
                break;
            }
        }

        if (ok) puts("yes");
        else puts("no");
    }
}