#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
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
    ll n, m;
    cin >> n >> m;
    vvb s(m, vb(n, false));
    rep(i, m) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll si;
            cin >> si;
            s[i][si-1] = true;
        }
    }
    vl p(m);
    rep(i, m) cin >> p[i];

    ll ans = 0;
    rep(i, 1 << n) {
        bitset<10> bit(i);
        bool ok = true;
        rep(j, m) {
            ll c = 0;
            rep(l, n) {
                if (bit.test(l) && s[j][l]) c++; 
            }
            if (abs(c - p[j]) % 2 != 0) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}