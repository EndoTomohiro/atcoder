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

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    ll q;
    cin >> q;

    vl b(q);
    rep(i, q) cin >> b[i];

    rep(i, q) {
        ll less = lower_bound(all(a), b[i]) - a.begin();
        if (less == 0) cout << abs(a[0] - b[i]) << endl;
        else cout << min(abs(a[less - 1] - b[i]), abs(a[less] - b[i])) << endl;
    }
}