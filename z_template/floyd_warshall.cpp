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
    ll n, m;
    cin >> n >> m;

    vvl dp(n, vl(n, INF));

    rep(i, m) {
        ll a, b, t;
        cin >> a >> b >> t;
        //a--; b--;

        dp[a][b] = t;
        //dp[b][a] = t;
    }
    rep(i, n) dp[i][i] = 0;

    rep(k, n) rep(i, n) rep(j, n) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    rep(i, n) {
        rep(j, n) {
            if (j) cout << ' ';
            if (dp[i][j] < INF/2) cout << dp[i][j];
            else cout << "INF";
        }
        cout << endl;
    }
}