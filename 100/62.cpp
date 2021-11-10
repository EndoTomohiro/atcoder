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
    ll h, w;
    cin >> h >> w;

    vvl c(10, vl(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    rep(k, 10) rep(i, 10) rep(j, 10) {
        chmin(c[i][j], c[i][k] + c[k][j]);
    }

    ll ans = 0;
    rep(i, h) rep(j, w) {
        ll a;
        cin >> a;
        if (a == -1) continue;
        ans += c[a][1];
    }

    cout << ans << endl;
}