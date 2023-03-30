#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const ll INF = 500;
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
    ll n, x, y;
    cin >> n >> x >> y;

    vl a(n+1), b(n+1);
    rep(i, n) cin >> a[i+1] >> b[i+1];

    vvvl dp(n+1, vvl(x+1, vl(y+1, INF)));
    dp[0][0][0] = 0;

    rep2(i, 1, n+1) rep(j, x+1) rep(k, y+1) {
        chmin(dp[i][min(j+a[i], x)][min(k+b[i], y)], dp[i-1][j][k]+1);
        chmin(dp[i][j][k], dp[i-1][j][k]);
    }

    if (dp[n][x][y] == INF) cout << -1 << endl;
    else cout << dp[n][x][y] << endl;
}
