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

int main() {
    ll n, m;
    cin >> n >> m;

    vl a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    rep(i, m) mp[a[i]]++;

    ll ans;
    rep(i, m + 1) {
        if (mp[i] == 0) {
            ans = i;
            break;
        }
    }

    rep(i, n - m) {
        mp[a[i + m]]++;
        mp[a[i]]--;
        if (mp[a[i]] == 0) chmin(ans, a[i]);
    }

    cout << ans << endl;
}