#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
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

    vl a(n+1), b(n+1);
    rep2(i, n) cin >> a[i];
    rep2(i, n) cin >> b[i];

    vvl dp(n+1, vl(3001));

    rep2(i, n) rep(j, 3001) {
        if (i == 1) {
            if (!j) {
                if (a[i] <= j && j <= b[i]) dp[i][j] = 1;
            }
            else {
                if (a[i] <= j && j <= b[i]) dp[i][j] = dp[i][j-1] + 1;
                else dp[i][j] = dp[i][j-1];
            }
        }
        else {
            if (!j) {
                if (a[i] <= j && j <= b[i]) dp[i][j] = dp[i-1][j];
            }
            else {
                if (a[i] <= j && j <= b[i]) dp[i][j] = dp[i][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i][j-1];
            }
        }
        dp[i][j] %= 998244353;
    }

    cout << dp[n][3000] << endl;
}