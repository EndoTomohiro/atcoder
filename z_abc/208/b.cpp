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

ll kaijou(ll n) {
    ll ans = 1;
    rep2(i, 1, n+1) ans *= i;
    return ans;
}

int main() {
    ll p;
    cin >> p;

    ll ans = 0;
    ll n = 10;
    while (p > 0) {
        while (p >= kaijou(n)) {
            p -= kaijou(n);
            ans++;
        }
        n--;
    }

    cout << ans << endl;
}