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

const ll big = 10000000000000;

int main() {
    ll n, m;
    cin >> n >> m;

    vvl dp(n, vl(n, big));
    rep(i, m) {
        ll s, t, c;
        cin >> s >> t >> c;
        s--; t--;
        dp[s][t] = c;
    }
    rep(i, n) dp[i][i] = 0;
    
    ll ans = 0;
    rep(l, n) {
        rep(i, n) rep(j, n) dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
        rep(i, n) rep(j, n) {
            if (dp[i][j] < big) ans += dp[i][j];
        }
    }

    cout << ans << endl;
}