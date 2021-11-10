#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
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

    vvl a(h, vl(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    vl sum_h(h), sum_w(w);
    rep(i, h) rep(j, w) sum_h[i] += a[i][j];
    rep(j, w) rep(i, h) sum_w[j] += a[i][j];

    rep(i, h) rep(j, w) {
        cout << sum_h[i] + sum_w[j] - a[i][j];
        if (j != w - 1) cout << ' ';
        else cout << endl;
    }
}