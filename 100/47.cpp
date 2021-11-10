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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    ll dp[2*n][2*n];
    rep(i, 2*n) rep(j, 2*n) dp[i][j] = -big;
    rep(i, 2*n) dp[i][i] = a[i%n];

    rep(l, n-1) {
        rep2(i, 1, 2*n-1-l) {
            ll j = i + l;
            if (l % 2 == 0) {
                if (dp[i-1][i-1] > dp[j+1][j+1]) chmax(dp[i-1][j], dp[i][j]);
                else chmax(dp[i][j+1], dp[i][j]);
            }
            else {
                chmax(dp[i-1][j], dp[i][j] + dp[i-1][i-1]);
                chmax(dp[i][j+1], dp[i][j] + dp[j+1][j+1]);
            }
        }
    }

    ll ans = 0;
    rep(i, n+1) chmax(ans, dp[i][i+n-1]);
    cout << ans << endl;
}