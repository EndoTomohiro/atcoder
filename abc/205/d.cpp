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
    ll n, q;
    cin >> n >> q;
    vl a(n), c(n);
    rep(i, n) {
        cin >> a[i];
        c[i] = a[i] - 1 - i;
    }
    rep(i, q) {
        ll k;
        cin >> k;
        ll index = lower_bound(all(c), k) - c.begin();
        if (index == n) {
            cout << a[n-1] + k - c[n-1] << endl;
            continue;
        }
        cout << a[index] - 1 - (c[index] - k) << endl;
    }
}