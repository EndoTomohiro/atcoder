#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvb = vector<vb>;
using ql = queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
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

int main() {
    vvl a(3, vl(3));
    rep(i, 3) rep(j, 3) cin >> a[i][j];
    ll n;
    cin >> n;
    vl b(n);
    rep(i, n) cin >> b[i];

    vvb vec(3, vb(3, false));
    rep(i, 3) rep(j, 3) {
        if (count(all(b), a[i][j])) vec[i][j] = true;
    }

    rep(i, 3) {
        bool ok = true;
        rep(j, 3) {
            if (!vec[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    }

    rep(j, 3) {
        bool ok = true;
        rep(i, 3) {
            if (!vec[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    }

    if (vec[0][0] && vec[1][1] && vec[2][2] || vec[0][2] && vec[1][1] && vec[2][0]) {
        puts("Yes");
        return 0;
    }

    puts("No");
}
