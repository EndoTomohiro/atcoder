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

    vl va(46), vb(46), vc(46);

    rep(i, n) {
        ll a;
        cin >> a;
        va[a%46]++;
    }

    rep(i, n) {
        ll b;
        cin >> b;
        vb[b%46]++;
    }

    rep(i, n) {
        ll c;
        cin >> c;
        vc[c%46]++;
    }

    ll ans = 0;

    rep(i, 46) rep(j, 46) rep(k, 46) {
        if ((i + j + k) % 46 == 0) ans += va[i] * vb[j] * vc[k];
    }

    cout << ans << endl;
}