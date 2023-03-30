#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];

    ll ans = 2000000000;

    rep(i, 1 << (n - 1)) {
        ll xored = 0;
        ll ored = 0;
        rep(j, n + 1) {
            if (j < n) ored |= a[j];
            if (j == n || (i >> j & 1)) xored ^= ored, ored = 0;
        }
        chmin(ans, xored);
    }

    cout << ans << endl;
}