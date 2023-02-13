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
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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

bool comp(pl pi, pl pj) {
    ll xi = pi.first;
    ll yi = pi.second;
    ll xj = pj.first;
    ll yj = pj.second;
    if (xi != xj) return xi < xj;
    else return yi > yj;
}

int main() {
    ll n;
    cin >> n;
    vp xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;
    sort(all(xy), comp);

    vl dp(n, INF);

    rep(i, n) {
        ll yi = xy[i].second;
        ll less = lower_bound(all(dp), yi) - dp.begin();
        dp[less] = yi;
    }

    ll ans = 0;
    rep(i, n) {
        if (dp[i] != INF) ans++;
        else break;
    }

    cout << ans << endl;
}
