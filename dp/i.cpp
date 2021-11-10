#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

vector<double> p(3000);
vector< vector<double> > dp(3000, vector<double>(3000));

int main() {
    int n;
    cin >> n;

    rep2(i, 1, n+1) cin >> p[i];

    dp[0][0] = 1;
    dp[0][1] = 1;

    rep2(i, 1, n+1) rep(j, i+1) {
        if (j == 0) dp[i][j] = dp[i-1][j] * (1 - p[i]);
        else if (i == 1) dp[i][j] = dp[i-1][j-1] * p[i];
        else dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
    }

    double sum = 0.0;

    rep2(i, (n+1)/2, n+1) {
        sum += dp[n][i];
    }

    cout << fixed << setprecision(10);
    cout << sum << endl;
}