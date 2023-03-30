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
using ml = map<ll, ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vl p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    sort(all(p), greater<ll>());
    sort(all(q), greater<ll>());
    sort(all(r), greater<ll>());

    ll na = 0, nb = 0, nc = 0, ans = 0;
    rep(i, x + y) {
        ll max_i = 0;
        ll max_r = 0;
        if (na < x) {
            if (chmax(max_i, p[na])) {
                max_r = 1;
            }
        }
        if (nb < y) {
            if (chmax(max_i, q[nb])) {
                max_r = 2;
            }
        }
        if (nc < c) {
            if (chmax(max_i, r[nc])) {
                max_r = 3;
            }
        }
        ans += max_i;
        if (max_r == 1) na++;
        else if (max_r == 2) nb++;
        else nc++;
    }

    cout << ans << endl;
}
