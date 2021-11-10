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
    ll n, m, t;
    cin >> n >> m >> t;
    const ll y = n;

    vector<ll> a(m+1), b(m+1);
    a[0] = 0, b[0] = 0;
    rep(i, m) cin >> a[i+1] >> b[i+1];

    string ok = "Yes";

    rep(i, m) {
        n -= a[i+1] - b[i];
        if (n <= 0) {
            ok = "No";
            break;
        }

        n = min(n + b[i+1] - a[i+1], y);
    }

    n -= t - b[m];
    if (n <= 0) ok = "No";

    cout << ok << endl;
}