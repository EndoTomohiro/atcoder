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
    ll h, w;
    cin >> h >> w;

    vvl a(h, vl(w)), b(h, vl(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];

    vvl c(h, vl(w));
    rep(i, h) rep(j, w) c[i][j] = b[i][j] - a[i][j];

    ll ans = 0;

    rep(i, h-1) rep(j, w-1) {
        ans += abs(c[i][j]);
        c[i+1][j] -= c[i][j];
        c[i][j+1] -= c[i][j];
        c[i+1][j+1] -= c[i][j];
        c[i][j] = 0;
    }

    rep(i, h) {
        if (c[i][w-1] != 0) {
            cout << "No" << endl;
            exit(0);
        }
    }

    rep(j, w) {
        if (c[h-1][j] != 0) {
            cout << "No" << endl;
            exit(0);
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;
}