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

ll pow2(ll x) {
    return x * x;
}

ll f(pair<ll, ll> x, pair<ll, ll> y) {
    return pow2(x.first - y.first) + pow2(x.second - y.second);
}

int main() {
    ll n;
    cin >> n;

    vp a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    sort(all(a));

    ll ans = 0;

    rep(i, n-1) rep2(j, i+1, n) {
        pa q(a[j].first - a[j].second + a[i].second, a[j].second + a[j].first - a[i].first);
        pa r(a[i].first - a[j].second + a[i].second, a[i].second + a[j].first - a[i].first);

        ll c = 0;
        rep(k, n) {
            if (a[k] == q || a[k] == r) c++;
            if (c == 2) break;
        }

        if (c == 2) chmax(ans, f(a[i], a[j]));
    }

    cout << ans << endl;
}