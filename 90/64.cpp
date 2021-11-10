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
    ll n, q;
    cin >> n >> q;

    vl a(n), difa(n-1);
    ll ans = 0;

    rep(i, n) {
        cin >> a[i];
        if (i) {
            difa[i-1] = a[i] - a[i-1];
            ans += abs(difa[i-1]);
        }
    }

    vl l(q), r(q), v(q);
    rep(i, q) {
        cin >> l[i] >> r[i] >> v[i];
        l[i]--; r[i]--;
    }

    rep(i, q) {
        if (l[i] > 0) {
            ans -= abs(difa[l[i] - 1]);
            difa[l[i] - 1] += v[i];
            ans += abs(difa[l[i] - 1]);
        }
        if (r[i] < n - 1) {
            ans -= abs(difa[r[i]]);
            difa[r[i]] -= v[i];
            ans += abs(difa[r[i]]);
        }
        cout << ans << endl;
    }
}