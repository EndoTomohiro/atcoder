#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vvt = vector<vt>;
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

    ll kinds = 1000001;

    vl table(kinds);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        table[a]++;
        if (b != kinds - 1) table[b+1]--;
    }

    rep2(i, 1, kinds) table[i] += table[i-1];

    ll ans = 0;
    rep(i, kinds) chmax(ans, table[i]);

    cout << ans << endl;
}