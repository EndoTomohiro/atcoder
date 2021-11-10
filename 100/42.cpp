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
const ll big = 100000000000000000;
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
    ll n, m;
    cin >> n >> m;
    vl d(n+1), c(m+1);
    rep2(i, 1, n+1) cin >> d[i];
    rep2(j, 1, m+1) cin >> c[j];

    ll dp[n+1][m+1];
    rep(i, n+1) rep(j, m+1) dp[i][j] = big;
    rep(j, m+1) dp[0][j] = 0;
    rep2(i, 1, n+1) {
        rep2(j, i, m+1) {
            dp[i][j] = min(dp[i-1][j-1] + d[i] * c[j], dp[i][j-1]);
        }
    }

    ll ans = big;
    rep2(j, n, m+1) chmin(ans, dp[n][j]);

    cout << ans << endl;
}