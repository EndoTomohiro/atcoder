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
    ll n, m;
    cin >> n >> m;
    vl s(m), c(m);
    rep(i, m) cin >> s[i] >> c[i];

    ll a = 0, b = 10;
    if (n == 2) a = 10, b = 100;
    if (n == 3) a = 100, b = 1000;
    rep3(i, a, b) {
        string si = to_string(i);
        bool ok = true;
        rep(j, m) {
            if (si[s[j] - 1] - '0' != c[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
