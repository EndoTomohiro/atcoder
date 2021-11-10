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

const ll x = 1000000007;

ll calc(ll a, ll b, ll x) {
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        ll d = calc(a, b / 2, x);
        return (d * d) % x;
    }
    else return (a * calc(a, b - 1, x)) % x;
}

int main() {
    ll w, h;
    cin >> w >> h;
    w--; h--;

    ll ans = 1;
    rep(i, w + h) {
        ans = ans * (i + 1) % x;
    }

    rep(i, w) ans = ans * calc(i + 1, x - 2, x) % x;
    rep(i, h) ans = ans * calc(i + 1, x - 2, x) % x;

    cout << ans << endl;
}