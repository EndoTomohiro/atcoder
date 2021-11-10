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
    int k;
    cin >> k;

    if (k % 9 != 0) {
        cout << 0 << endl;
        exit(0);
    }

    vl dp(k+1);

    dp[0] = 1;

    rep2(i, 1, k+1) {
        int b = min(int(i), 9);
        rep2(j, 1, b+1) dp[i] += dp[i-j];
        dp[i] %= 1000000007;
    }

    cout << dp[k] << endl;
}