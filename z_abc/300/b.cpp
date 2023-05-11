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
using vvc = vector<vc>;
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
    vs a(h), b(h);
    rep(i, h) cin >> a[i];
    rep(i, h) cin >> b[i];

    rep(s, h) rep(t, w) {
        vvc c(h, vc(w));
        rep(i, h) rep(j, w) c[(i+s)%h][j] = a[i][j];
        vvc d(h, vc(w));
        rep(i, h) rep(j, w) d[i][(j+t)%w] = c[i][j];
        bool ok = true;
        rep(i, h) rep(j, w) {
            if (d[i][j] != b[i][j]) ok = false;
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
