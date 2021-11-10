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
    ll n, p, q;
    cin >> n >> p >> q;

    vl a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;

    rep(i, n-4) {
        ll ama = a[i] % p;
        rep2(j, i+1, n-3) {
            ll ama2 = ama * a[j] % p;
            rep2(k, j+1, n-2) {
                ll ama3 = ama2 * a[k] % p;
                rep2(l, k+1, n-1) {
                    ll ama4 = ama3 * a[l] % p;
                    rep2(m, l+1, n) {
                        ll ama5 = ama4 * a[m] % p;
                        if (ama5 == q) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}