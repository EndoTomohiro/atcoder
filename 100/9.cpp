#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
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

int main () {
    ll m;
    cin >> m;

    vp a(m);
    rep(i, m) cin >> a[i].first >> a[i].second;
    sort(all(a));

    ll n;
    cin >> n;

    vp b(n);
    rep(i, n) cin >> b[i].first >> b[i].second;
    sort(all(b));

    rep(i, n-m) {
        ll x = b[i].first - a[0].first;
        ll y = b[i].second - a[0].second;

        if (m == 1) {
            cout << x << ' ' << y << endl;
            return 0;
        }

        ll c = 1;
        rep2(j, i+1, n) {
            if (b[j].first - x == a[c].first && b[j].second - y == a[c].second) c++;
            if (c == m) break;
        }

        if (c == m) {
            cout << x << ' ' << y << endl;
            return 0;
        }
    }
}