#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
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

// 累乗
ll myPow(ll x, ll n){
    ll p = x, ans = 1;
    rep(i, 60) {
        ll wari = (1LL << i);
        if ((n / wari) % 2 == 1) ans = ans * p % dif;
        p = p * p % dif;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    ll x = 1;
    rep(i, r) x = x * (n - i) % dif;
    ll y = 1;
    rep2(i, r) y = y * i % dif;
    ll ans = x * myPow(y, dif - 2) % dif;
    return ans;
}

int main() {
    ll h, w;
    cin >> h >> w;
    cout << nCr(h + w - 2, h - 1) << endl;
}
