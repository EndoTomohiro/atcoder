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

ll day[110];
ll dp[110][3][3];

int main() {
    ll n, k;
    cin >> n >> k;
    memset(day, -1, sizeof(day));
    rep(i, k) {
        ll a, b;
        cin >> a >> b;
        day[a-1] = b-1;
    }

    dp[0][0][0] = 1;

    rep(i, n) rep(a, 3) rep(b, 3) {
        vl cs = {0, 1, 2};
        if (day[i] >= 0) cs = {day[i]};
        for (ll c : cs) {
            if (i >= 2 && a == b && b == c) continue;
            dp[i+1][b][c] += dp[i][a][b];
            dp[i+1][b][c] %= 10000;
        }
    }

    ll ans = 0;
    rep(a, 3) rep(b, 3) {
        ans += dp[n][a][b];
        ans %= 10000;
    }

    cout << ans << endl;
}