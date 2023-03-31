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
    ll n, x;
    cin >> n >> x;
    vvb dp(n + 1, vb(10010));
    dp[0][0] = true;
    rep2(i, n) {
        ll a, b;
        cin >> a >> b;
        rep3(j, a, x) {
            if (dp[i - 1][j - a]) dp[i][j] = true;
        }
        rep3(j, b, x) {
            if (dp[i - 1][j - b]) dp[i][j] = true;
        }
    }
    if (dp[n][x]) puts("Yes");
    else puts("No");
}