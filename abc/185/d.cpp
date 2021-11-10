#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
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

    vector<ll> a(m+2);
    a[0] = 0;
    rep(i, m) cin >> a[i+1];
    a[m+1] = n+1;

    sort(a.begin(), a.end());

    ll num_white = 0;
    ll wide = n;

    rep(i, m+1) {
        ll numi_white = a[i+1] - a[i] -1;
        num_white += numi_white;
        if (numi_white > 0) chmin(wide, numi_white);
    }

    ll c = 0;
    rep(i, m+1) {
        ll numi_white = a[i+1] - a[i] -1;
        c += (numi_white + wide - 1) / wide; 
    }

    cout << c << endl;
}