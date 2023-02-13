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
    string s, t;
    cin >> s >> t;
    ll h = s.size(), w = t.size();
    vvl dp(h+1, vl(w+1));
    rep(i, h+1) {
        rep(j, w+1) {
            if (i && j && s[i-1] == t[j-1]) dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]});
            else if (i && j) dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            else if (j) dp[i][j] = dp[i][j-1] + 1;
            else if (i) dp[i][j] = dp[i-1][j] + 1;
        }
    }
    cout << dp[h][w] << endl;
}
