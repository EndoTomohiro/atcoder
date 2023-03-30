#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
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

    vl a(n);
    vl b(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
    sort(all(a));
    sort(all(b));

    ll ac = 0, bc = 0, ans = INF;
    while (ac < n && bc < m) {
        ll num = a[ac] - b[bc];
        chmin(ans, abs(num));
        if (num < 0) ac++;
        else bc++;
    }

    cout << ans << endl;
}