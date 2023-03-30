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
    ll n, m;
    cin >> n >> m;

    vl a(n);
    rep(i, n) cin >> a[i];

    vvl graph(n, vl(0));
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }

    vl dp(n, INF);

    rep(i, n) {
        rep(l, graph[i].size()) {
            ll j = graph[i][l];
            dp[j] = min({dp[j], dp[i], a[i]});
        }
    }

    ll ans = -INF;
    rep(i, n) chmax(ans, a[i] - dp[i]);

    cout << ans << endl;
}