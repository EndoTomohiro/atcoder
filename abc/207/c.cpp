#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vd = vector<double>;
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
    ll n;
    cin >> n;
    vd l(n), r(n);
    rep(i, n) {
        ll t;
        cin >> t >> l[i] >> r[i];
        if (t == 2) {
            r[i] -= 0.1;
        }
        if (t == 3) {
            l[i] += 0.1;
        }
        if (t == 4) {
            l[i] += 0.1;
            r[i] -= 0.1;
        }
    }
    
    ll ans = 0;
    rep(i, n-1) rep2(j, i+1, n) {
        if (l[i] <= l[j] && l[j] <= r[i]) ans++;
        else if (l[j] <= l[i] && l[i] <= r[j]) ans++;
    }

    cout << ans << endl;
}