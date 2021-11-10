#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    ll n, w;
    cin >> n >> w;

    vector< pair<ll, ll> > wv(n);
    rep(i, n) cin >> wv[i].first >> wv[i].second;

    vector< vector<ll> > dp(n+1, vector<ll>(w+1));

    rep(i, w+1) {
        dp[0][i] = 0;
    }
    rep(i, n+1) {
        dp[i][0] = 0;
    }

    rep(i, n) {
        rep(j, w) {
            if (j+1 - wv[i].first < 0) dp[i+1][j+1] = dp[i][j+1];
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i][j+1-wv[i].first] + wv[i].second);
        }
    }

    cout << dp[n][w] << endl;
}