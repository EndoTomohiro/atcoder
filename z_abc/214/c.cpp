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
    ll n;
    cin >> n;

    vl s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    ll min_t = INF;
    ll min_i = -1;
    rep(i, n) {
        if (t[i] < min_t) {
            min_t = t[i];
            min_i = i;
        }
    }

    vl ans(n);
    rep(j, n) {
        ll i = (j + min_i) % n;
        if (i == 0) ans[i] = min(t[i], s[n-1] + ans[n-1]);
        else ans[i] = min(t[i], s[i-1] + ans[i-1]);
    }

    rep(i, n) cout << ans[i] << endl;
}