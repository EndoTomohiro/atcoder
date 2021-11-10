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

vector< vector<ll> > g(100001, vector<ll>());
vector<ll> dp(100001, -1);

ll rec(ll v) {
    if (dp[v] != -1) return dp[v];

    ll res = 0;
    for (auto nv : g[v]) chmax(res, rec(nv) + 1);
    return dp[v] = res;
}

int main() {
    int n, m;
    cin >> n >> m;

    rep2(i, 1, m+1) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    ll res = 0;
    rep2(i, 1, n+1) chmax(res, rec(i));

    cout << res << endl;
}