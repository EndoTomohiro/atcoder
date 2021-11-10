#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n), p(n), x(n);
    rep(i, n) cin >> a[i] >> p[i] >> x[i];

    ll money = 1000000000;
    bool ok = false;

    rep(i, n) {
        if (a[i] < x[i]) {
            ok = true;
            chmin(money, p[i]);
        }
    }

    if (ok) cout << money << endl;
    else puts("-1");
}