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

ll max_same(vl r) {
    map<ll, ll> Map;
    ll ret = 0;
    rep(i, r.size()) {
        Map[r[i]]++;
        chmax(ret, Map[r[i]]);
    }
    return ret;
}

int main() {
    ll h, w;
    cin >> h >> w;

    vvl p(h, vl(w));
    rep(i, h) rep(j, w) cin >> p[i][j];

    ll ans = 1;

    rep3(i, 1, 1 << h) {
        bitset<8> bit(i);
        vl vec, r;
        rep(j, 8) {
            if (bit.test(j)) vec.push_back(j);
        }

        rep(k, w) {
            ll same = p[vec[0]][k];
            bool tf = true;
            rep(l, vec.size()) {
                if (p[vec[l]][k] != same) {
                    tf = false;
                    break;
                }
            }
            if (tf) r.push_back(same);
        }

        ll ansi = vec.size() * max_same(r);
        chmax(ans, ansi);
    }

    cout << ans << endl;
}