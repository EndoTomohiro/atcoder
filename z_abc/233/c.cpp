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
using ml = map<ll, ll>;
const double pi = 3.14159265359;
const ll INF = 1100000000000000000;
const ll dif = 1000000007;
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
    ll n, x;
    cin >> n >> x;

    ql que;
    que.push(1);
    ll cnt = 1;
    rep(j, n) {
        ll l;
        cin >> l;
        vl a(l);
        rep(i, l) cin >> a[i];
        ll ng = 0;
        rep(k, cnt) {
            ll v = que.front();
            que.pop();
            rep(i, l) {
                if (INF / a[i] > v) que.push(v * a[i]);
                else ng++;
            }
        }
        cnt *= l;
        cnt -= ng;
    }

    ll ans = 0;
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        if (v == x) ans++;
    }

    cout << ans << endl;
}
