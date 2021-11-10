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
    ll n, m, q;
    cin >> n >> m >> q;

    vvl acc(n+2, vl(n+1));

    rep(i, m) {
        ll l, r;
        cin >> l >> r;
        acc[l][r]++;
    }

    rep(k, n) rep2(i, 1, n+1-k) {
        ll j = i + k;
        acc[i][j] += acc[i+1][j] + acc[i][j-1] - acc[i+1][j-1];
    }

    vl ans(q);
    rep(i, q) {
        ll s, t;
        cin >> s >> t;
        ans[i] = acc[s][t];
    }

    rep(i, q) cout << ans[i] << endl;
}