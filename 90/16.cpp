#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    vl vec = {a, b, c};
    sort(all(vec));

    a = vec[2];
    b = vec[1];
    c = vec[0];

    ll ans = 100000;
    
    rep(x, ans) rep(y, ans) {
        ll tmp = x * a + y * b;
        if ((n - tmp) % c != 0 || tmp > n) continue;
        ll z = (n - tmp) / c;
        chmin(ans, x + y + z);
    }

    cout << ans << endl;
}