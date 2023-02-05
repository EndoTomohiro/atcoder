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
#define rep(i, n) for (ll i = 1; i < (ll)(n); i++)
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

ll myPow(ll x, ll n){
    if (n == 0) return 1;
    else if (n % 2 == 0) return myPow(x * x % dif, n / 2);
    else return x * myPow(x, n - 1) % dif;
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
    ll n, m, k;
    cin >> n >> m >> k;
    vvl dp(n, vl(k+1, 0));
    rep(j, m+1) dp[0][j]++;
    rep(i, n) rep3(j, i+1, k+1) {
        rep(l, m+1) {
            if (j - l <= 0) break;
            else dp[i][j] += dp[i-1][j-l];
        }
        dp[i][j] %= dif;
    }
    ll ans = 0;
    rep(j, k+1) ans += dp[n-1][j];
    ans %= dif;
    cout << ans << endl;
}
