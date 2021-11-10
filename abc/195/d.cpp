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
    ll n, m, q;
    cin >> n >> m >> q;

    vp vw(n);
    rep(i, n) cin >> vw[i].second >> vw[i].first;
    sort(vw.begin(), vw.end(), greater<pl>());

    vl x(m);
    rep(i, m) cin >> x[i];

    vp lr(q);
    rep(i, q) cin >> lr[i].first >> lr[i].second;

    rep(i, q) {
        vl ex(0);
        rep(j, m) {
            if (j < lr[i].first - 1 || j > lr[i].second - 1) {
                ex.push_back(x[j]);
            }
        }
        sort(all(ex));

        ll len = ex.size();
        vector<bool> used(len, true);
        ll ansi = 0;

        rep(a, n) {
            if (ex.size() == 0) break;
            
            ll value = vw[a].first;
            ll weight = vw[a].second;

            rep(b, len) {
                if (weight <= ex[b] && used[b]) {
                    ansi += value;
                    used[b] = false;
                    break;
                }
            }
        }

        cout << ansi << endl;
    }
}