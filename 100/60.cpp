#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
const long long INF = 10000000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rep3(i, s, n) for (int i = (int)(n); i >= (int)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector< vector<long long> > dp(v, vector<long long>(v, INF));

    rep(i, e) {
        int a, b, w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    rep(i, v) dp[i][i] = 0;

    rep(k, v) rep(i, v) rep(j, v) {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }

    bool negative = false;
    rep(i, v) if (dp[i][i] < 0) negative = true;

    if (negative) cout << "NEGATIVE CYCLE" << endl;

    else {
        rep(i, v) {
            rep(j, v) {
                if (j) cout << ' ';
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
}