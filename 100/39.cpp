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
    ll n;
    cin >> n;
    vl vec(n);
    rep(i, n) cin >> vec[i];

    vvl dp(n-1, vl(21));
    dp[0][vec[0]] = 1;
    rep(i, n-2) {
        rep(j, 21) {
            if (j - vec[i+1] >= 0) dp[i+1][j] += dp[i][j - vec[i+1]];
            if (j + vec[i+1] <= 20) dp[i+1][j] += dp[i][j + vec[i+1]];
        }
    }

    cout << dp[n-2][vec[n-1]] << endl;
}