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

ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;

    ll ans10 = 1;
    ll ans9 = 1;
    ll ans8 = 1;

    rep(i, n) {
        ans10 *= 10;
        ans10 %= mod;
        ans9 *= 9;
        ans9 %= mod;
        ans8 *= 8;
        ans8 %= mod;
    }

    ll ans = ans10 - ans9 * 2 + ans8;

    while (ans < 0) ans += mod;
    while (ans >= mod) ans -= mod;

    cout << ans << endl;
}