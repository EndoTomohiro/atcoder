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
    ll n, m, k;
    cin >> n >> m >> k;

    vvl dp(n, vl(m));
    rep(i, m) dp[0][i] = 1;
    vl s(m+1);
    rep2(i, n-1) {
        rep(j, m) s[j+1] = s[j] + dp[i-1][j];
        rep(j, m) {
            if (k == 0) dp[i][j] = s[m];
            else {
                if (j - k >= 0) dp[i][j] += s[j - k + 1];
                if (j + k < m) dp[i][j] += s[m] - s[j + k];
            }
            dp[i][j] %= dif;
        }
    }
    cout << accumulate(all(dp[n-1]), ll(0)) % dif << endl;
}
