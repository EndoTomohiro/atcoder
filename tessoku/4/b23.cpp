#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vd>;
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

double dis(ll xi, ll xj, ll yi, ll yj) {
    return double(sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)));
}

int main() {
    ll n;
    cin >> n;
    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vvl dp(1<<18, vd(n, INF));
    dp[0][0] = 0;
    rep(i, 1<<n) rep(j, n) {
        if (dp[i][j] == INF) continue;
        rep(k, n) {
            if ((i / (1 << k)) % 2 == 0) chmin(dp[i+(1<<k)][k], dp[i][j] + dis(x[j], x[k], y[j], y[k]));
        }
    }
    cout << dp[(1<<n)-1][0] << endl;
}
