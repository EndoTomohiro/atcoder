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
const ll big = 100000000000000000;
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

ll count(vs s, ll j, char c) {
    ll ans = 0;
    rep(i, 5) if (s[i][j] == c) ans++;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vs s(5);
    rep(i, 5) cin >> s[i];

    ll dp[n][3];
    rep(i, n) rep(j, 3) dp[i][j] = 0;
    rep(i, n) {
        if (i == 0) {
            dp[0][0] = 5 - count(s, 0, 'R');
            dp[0][1] = 5 - count(s, 0, 'B');
            dp[0][2] = 5 - count(s, 0, 'W');
        }
        else {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + 5 - count(s, i, 'R');
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + 5 - count(s, i, 'B');
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + 5 - count(s, i, 'W');
        }
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}