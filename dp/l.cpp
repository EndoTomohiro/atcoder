#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
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
    int n;
    cin >> n;

    vector<ll> a(n+1);
    rep2(i, 1, n+1) cin >> a[i];

    vector< vector<ll> > dp(n+1, vector<ll>(n+1));

    rep2(i, 1, n+1) dp[i][i] = a[i];

    rep2(k, 1, n) rep2(i, 1, n+1-k) {
        int j = i + k;
        dp[i][j] = max(a[j] - dp[i][j - 1], a[i] - dp[i + 1][j]);
    }

    cout << dp[1][n] << endl;
}