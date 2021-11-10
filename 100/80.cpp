#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vvt = vector<vt>;
using vs = vector<string>;
#define pi 3.14159265359;
const ll INF = 1000000000000000;
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
    ll h, w, k, v;
    cin >> h >> w >> k >> v;

    vvl vec(h+1, vl(w+1));
    rep(i, h) rep(j, w) cin >> vec[i+1][j+1];

    vvl acc(h+1, vl(w+1));
    rep(i, h) rep(j, w) {
        acc[i+1][j+1] = acc[i][j+1] + acc[i+1][j] - acc[i][j] + vec[i+1][j+1];
    }

    ll ans = 0;
    rep2(p, 1, h+1) rep2(q, 1, w+1) rep(s, h+1-p) rep(t, w+1-q) {
        ll i = s + p;
        ll j = t + q;
        ll money = acc[i][j] - acc[i-p][j] - acc[i][j-q] + acc[i-p][j-q] + p * q * k;
        if (money <= v) chmax(ans, p * q);
    }

    cout << ans << endl;
}