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

    vvl b(n, vl(m));
    rep(i, n) rep(j, m) cin >> b[i][j];

    vvl x(n, vl(m)), y(n, vl(m));

    rep(i, n) rep(j, m) {
        ll c = b[i][j];
        x[i][j] = (c + 6) / 7;
        y[i][j] = (c - 1) % 7 + 1;
    }

    string ans = "Yes";

    rep(i, n) rep(j, m) {
        if (0 < i && x[i][j] != x[i-1][j]+1) ans = "No";
        if (0 < j && y[i][j] != y[i][j-1]+1) ans = "No";
        if (0 < j && x[i][j] != x[i][j-1]) ans = "No";
        if (0 < i && y[i][j] != y[i-1][j]) ans = "No";
    }

    cout << ans << endl;
}