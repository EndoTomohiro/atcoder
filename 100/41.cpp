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

int main() {
    ll d, n;
    cin >> d >> n;
    vl t(d), a(n), b(n), c(n);
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    ll dp[d][n];
    rep(i, d) rep(j, n) dp[i][j] = -1;
    rep(j, n) {
        if (a[j] <= t[0] && t[0] <= b[j]) dp[0][j] = 0;
    }
    rep2(k, 1, d) {
        rep(j, n) {
            if (a[j] <= t[k] && t[k] <= b[j]) {
                rep(i, n) {
                    if (dp[k-1][i] >= 0) {
                        chmax(dp[k][j], dp[k-1][i] + abs(c[j] - c[i]));
                    }
                }
            }
        }
    }

    ll ans = 0;
    rep(i, n) chmax(ans, dp[d-1][i]);

    cout << ans << endl;
}