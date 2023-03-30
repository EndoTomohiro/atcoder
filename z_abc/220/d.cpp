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

ll mod = 998244353;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];

    vvl ans(n, vl(10));
    ans[0][a[0]] = 1;

    rep2(i, n-1) {
        rep(j, 10) {
            ll f = (a[i] + j) % 10;
            ll g = a[i] * j % 10;
            ans[i][f] += ans[i-1][j];
            ans[i][f] %= mod;
            ans[i][g] += ans[i-1][j];
            ans[i][g] %= mod;
        }
    }

    rep(i, 10) cout << ans[n-1][i] << endl;
}