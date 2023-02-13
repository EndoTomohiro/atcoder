#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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
    ll n, q;
    cin >> n >> q;
    vl w(n+1), v(n+1);
    rep2(i, n) cin >> w[i] >> v[i];
    vvl dp(n+1, vl(100010, INF));
    rep(i, n+1) dp[i][0] = 0;
    rep2(i, n) rep(j, 100001) {
        dp[i][j] = dp[i-1][j];
        if (j - v[i] >= 0) chmin(dp[i][j], dp[i-1][j-v[i]] + w[i]);
    }
    ll ans = -1;
    rep(j, 100001) {
        if (dp[n][j] <= q) ans = j;
    }
    cout << ans << endl;
}
