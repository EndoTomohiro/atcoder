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
    ll n;
    cin >> n;

    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll ans = 0;

    rep(i, n - 2) rep3(j, i + 1, n - 1) rep3(k, j + 1, n) {
        ll dx1 = x[j] - x[i];
        ll dx2 = x[k] - x[j];
        ll dy1 = y[j] - y[i];
        ll dy2 = y[k] - y[j];
        if (dx2 * dy1 != dx1 * dy2) ans++;
    }

    cout << ans << endl;
}