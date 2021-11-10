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

ll nC2(ll n) {
    return n * (n-1) / 2;
}

int main() {
    int n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    ll pre = a[0];
    ll cnt = 0;
    ll ans = nC2(n);

    rep(i, n) {
        if (a[i] == pre) {
            cnt++;
        }
        else {
            ans -= nC2(cnt);
            pre = a[i];
            cnt = 1;
        }
    }

    ans -= nC2(cnt);

    cout << ans << endl;
}