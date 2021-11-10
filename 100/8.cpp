#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pa = pair<ll, ll>;
using vl = vector<ll>;
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

int main () {
    ll n;
    cin >> n;

    vl a(n), b(n);
    ll s = 0, g = 0;

    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    sort(all(a));
    sort(all(b));

    ll c = (n - 1) / 2;

    ll ans = 0;
    rep(i, n) ans += abs(a[i] - a[c]) + b[i] - a[i] + abs(b[i] - b[c]);

    cout << ans << endl;
}