#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvp = vector<vp>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
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
template<class T> void chbest(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    vs s(n);
    rep(i, n) cin >> s[i];
    ll q;
    cin >> q;
    vl u(q), v(q);
    rep(i, q) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    vvp dp(n, vp(n, {INF, 0}));
    rep(i, n) rep(j, n) {
        if (s[i][j] == 'Y') dp[i][j] = {1, a[j]};
    }
    rep(k, n) rep(i, n) rep(j, n) {
        ll cnt = dp[i][k].first + dp[k][j].first;
        ll value = dp[i][k].second + dp[k][j].second;
        if (cnt < dp[i][j].first || (cnt == dp[i][j].first && value > dp[i][j].second)) {
            dp[i][j] = {cnt, value};
        }
    }

    rep(i, q) {
        if (dp[u[i]][v[i]].first == INF) puts("Impossible");
        else cout << dp[u[i]][v[i]].first << ' ' << dp[u[i]][v[i]].second + a[u[i]] << endl;
    }
}
