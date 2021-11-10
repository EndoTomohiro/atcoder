#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
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
    int N;
    ll W;
    cin >> N >> W;

    vector<ll> w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    vector< vector<ll> > dp(N + 1, vector<ll>(100000 + 1, 100000000000));

    dp[0][0] = 0;

    rep2(i, 1, N+1)rep(j, 100001){
        if(j - v[i-1] >= 0) dp[i][j] = min(dp[i-1][j], dp[i-1][j - v[i-1]] + w[i-1]);
        else dp[i][j] = dp[i-1][j];
    }

    int ans = 100000;
    while(dp[N][ans] > W) ans--;

    cout << ans << endl;
}