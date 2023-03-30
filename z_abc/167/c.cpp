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
const ll dif = 1000000007;
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
    ll n, m, x;
    cin >> n >> m >> x;

    vl c(n);
    vvl a(n, vl(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }

    ll ans = INF;

    rep(k, 1 << n) {
        bitset<12> bit(k);
        vl vec(m);
        ll money = 0;
        rep(i, n) {
            if (bit.test(i)) {
                money += c[i];
                rep(j, m) vec[j] += a[i][j]; 
            }
        }
        bool ok = true;
        rep(j, m) {
            if (vec[j] < x) {
                ok = false;
                break;
            }
        }
        if (ok) chmin(ans, money);
    }

    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}
