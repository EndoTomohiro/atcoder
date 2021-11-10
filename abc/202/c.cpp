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
#define rep2(i, s, n) for (ll i = (ll)(s); i <= (ll)(n); i++)
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
    vl a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) d[i] = b[c[i]-1];

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    ll ans = 0;
    ll as = 0, ds = 0;
    rep2(i, 1, n) {
        if (as >= n || ds >= n) break;
        if (a[as] == i && d[ds] == i) {
            ll ai = 0;
            ll di = 0;
            while (as < n && a[as] == i) {
                ai++;
                as++;
            }
            while (ds < n && d[ds] == i) {
                di++;
                ds++;
            }
            ans += ai * di;
        }
        if (as < n && a[as] == i) {
            while (as < n && a[as] == i) as++;
        }
        if (ds < n && d[ds] == i) {
            while (ds < n && d[ds] == i) ds++;
        }
    }

    cout << ans << endl;
}