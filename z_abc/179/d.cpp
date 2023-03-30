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

ll mod = 998244353;

int main() {
    ll n, k;
    cin >> n >> k;

    vl left(k), right(k);
    rep(i, k) cin >> left[i] >> right[i];

    vl dp(n);
    dp[0] = 1;

    rep(i, n - 1) {
        rep(j, k) {
            ll l = i + left[j];
            ll r = i + right[j] + 1;
            if (l < n) dp[l] += dp[i];
            if (r < n) {
                dp[r] -= dp[i];
                if (dp[r] < 0) dp[r] += mod;
            }
        }
        if (!i) dp[0]--;
        dp[i + 1] += dp[i];
        dp[i + 1] %= mod;
    }

    cout << dp[n - 1] << endl;
}