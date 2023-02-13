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

int main() {
    ll n;
    string s;
    cin >> n >> s;
    vvl dp(n, vl(n));
    rep(k, n) rep(i, n-k) {
                ll j = k + i;
                if (i < n - 1 && k >= 1 && s[i] == s[j]) dp[i][j] = max({dp[i+1][j], dp[i][j-1], dp[i+1][j-1] + 2});
                else if (i < n - 1 && k >= 1) dp[i][j] = max({dp[i+1][j], dp[i][j-1], dp[i+1][j-1]});
                else dp[i][j] = 1;
            }
    cout << dp[0][n-1] << endl;
}
