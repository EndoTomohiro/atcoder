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
using msl = multiset<ll>;
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

int main() {
    ll h, w;
    cin >> h >> w;
    vvl a(h, vl(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    ll n = h + w - 2, ans = 0;
    rep(i, 1 << n) {
        bitset<20> bit(i);
        ll cnt = 0;
        rep(j, n) if (bit.test(j)) cnt++;
        if (cnt != h - 1) continue;

        ll s = 0, t = 0;
        vl vec = {a[0][0]};
        rep(j, n) {
            if (bit.test(j)) s++;
            else t++;
            vec.push_back(a[s][t]);
        }
        sort(all(vec));
        vec.erase(unique(all(vec)), vec.end());
        if (vec.size() == n + 1) ans++;
    }
    cout << ans << endl;
}
