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

ll n;
bool ok(vvl a, vvl b) {
    rep(i, n) rep(j, n) {
        if (a[i][j] && !b[i][j]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    vvl a(n, vl(n)), b(n, vl(n)), c(n, vl(n)), d(n, vl(n)), e(n, vl(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) cin >> b[i][j];

    if (ok(a, b)) {
        puts("Yes");
        return 0;
    }

    rep(i, n) rep(j, n) c[i][j] = a[n - 1 - j][i];
    if (ok(c, b)) {
        puts("Yes");
        return 0;
    }

    rep(i, n) rep(j, n) d[i][j] = c[n - 1 - j][i];
    if (ok(d, b)) {
        puts("Yes");
        return 0;
    }

    rep(i, n) rep(j, n) e[i][j] = d[n - 1 - j][i];
    if (ok(e, b)) {
        puts("Yes");
        return 0;
    }

    puts("No");
}
