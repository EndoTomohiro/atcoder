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

// 連続する k 個の和の最大値を求める
int main() {
    ll n;
    cin >> n;

    vl a(n), s(n+1);
    rep(i, n) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    rep2(k, 1, n+1) {
        ll ans = 0;
        rep(i, n-k+1) chmax(ans, s[i+k] - s[i]);
        cout << ans << endl;
    }
}