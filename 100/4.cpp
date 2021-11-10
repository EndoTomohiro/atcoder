#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
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
    int n, m;
    cin >> n >> m;

    vvl a(n, vl(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    ll s_all = 0;
    rep(i, m-1) rep2(j, i+1, m) {
        ll s_ij = 0;
        rep(k, n) s_ij += max(a[k][i], a[k][j]);
        chmax(s_all, s_ij);
    }

    cout << s_all << endl;
}