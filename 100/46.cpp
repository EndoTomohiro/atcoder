#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
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
    int r[n], c[n];
    rep(i, n) cin >> r[i] >> c[i];

    int dp[n][n];
    rep(i, n) rep(j, n) dp[i][j] = 100000000;
    rep(i, n) dp[i][i] = 0;
    rep2(l, 1, n) rep(i, n-l) {
        int j = i + l;
        rep2(k, i, j) chmin(dp[i][j], dp[i][k] + dp[k+1][j] + r[i] * c[k] * c[j]);
    }

    cout << dp[0][n-1] << endl;
}