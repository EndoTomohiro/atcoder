#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vvt = vector<vt>;
using vs = vector<string>;
#define pi 3.14159265359;
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
    ll n, m;
    cin >> n >> m;

    vl p(m);
    rep(i, m) {
        cin >> p[i];
        p[i]--;
    }

    vl a(n-1), b(n-1), c(n-1);
    rep(i, n-1) cin >> a[i] >> b[i] >> c[i];

    vl table(n-1);
    rep(i, m-1) {
        ll start = min(p[i], p[i+1]);
        ll goal = max(p[i], p[i+1]);

        table[start]++;
        table[goal]--;
    }

    rep2(i, 1, n-1) table[i] += table[i-1];

    ll ans = 0;
    rep(i, n-1) ans += min(a[i] * table[i], b[i] * table[i] + c[i]);

    cout << ans << endl;
}