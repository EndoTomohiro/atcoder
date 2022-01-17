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
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i <= (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    vvb ans(q - p + 1, vb(s - r + 1, false));
    rep3(i, p, q) rep3(j, r, s) {
        if (i == a - b + j) {
            ll k = i - a;
            if (max(1 - a, 1 - b) <= k && k <= min(n - a, n - b)) ans[i - p][j - r] = true;
        }
        else if (i == a + b - j) {
            ll k = i - a;
            if (max(1 - a, b - n) <= k && k <= min(n - a, b - 1)) ans[i - p][j - r] = true;
        }
    }

    rep(i, ans.size()) {
        rep(j, ans[i].size()) {
            if (ans[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
}
