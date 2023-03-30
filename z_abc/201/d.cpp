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
    ll h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];

    vvl dp(h, vl(w));
    if (h + w == 2) {
        puts("Draw");
        return 0;
    }
    else if (h + w == 3) {
        if (a[h - 1][w - 1] == '+') puts("Takahashi");
        else puts("Aoki");
        return 0;
    }

    rep4(i, 0, h - 1) rep4(j, 0, w - 1) {
        ll x = 1;
        if ((i + j) % 2) x = -1;
        if (i == h - 1 && j == w - 1) continue;
        if (i == h - 1) {
            dp[i][j] = dp[i][j + 1];
            if (a[i][j + 1] == '+') dp[i][j] += x;
            else dp[i][j] -= x;
        }
        else if (j == w - 1) {
            dp[i][j] = dp[i + 1][j];
            if (a[i + 1][j] == '+') dp[i][j] += x;
            else dp[i][j] -= x;
        }
        else {
            ll s, t;
            if (a[i + 1][j] == '+') s = dp[i + 1][j] + x;
            else s = dp[i + 1][j] - x;
            if (a[i][j + 1] == '+') t = dp[i][j + 1] + x;
            else t = dp[i][j + 1] - x;
            if (x == 1) dp[i][j] = max(s, t);
            else dp[i][j] = min(s, t);
        }
    }
    
    if (dp[0][0] > 0) puts("Takahashi");
    else if (dp[0][0] < 0) puts("Aoki");
    else puts("Draw");
}