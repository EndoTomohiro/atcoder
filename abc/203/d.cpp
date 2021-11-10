#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
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
    int n, k;
    vvl a(n, vl(n));
    rep(i, n)rep(j, n) cin >> a[i][j];

    ll ans = 0;
    rep(i, n-k+1)rep(j, n-k+1) {
        vl pond;
        rep(x, k)rep(y, k) pond.push_back(a[i+x][j+y]);
        sort(pond.begin(), pond.end());
        chmin(ans, pond[k*k/2+1]);
        cout << ans << endl;
    }
    cout << ans << endl;
}