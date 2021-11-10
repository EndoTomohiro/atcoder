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

    vvl a(h, vl(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(i1, h - 1) rep3(i2, i1 + 1, h) rep(j1, w - 1) rep3(j2, j1 + 1, w) {
        if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
}