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
    ll n, s;
    cin >> n >> s;
    vl a(n);
    rep(i, n) cin >> a[i];
    vl dp(1000000);
    rep4(i, 0, n-1) {
        rep4(j, 0, s-a[i]+1) {
            if (dp[j] && !dp[j+a[i]]) dp[j+a[i]] = i + 1;
        }
        if (!dp[a[i]]) dp[a[i]] = i + 1;
    }
    if (!dp[s]) cout << -1 << endl;
    else {
        vl ans;
        ll pos = s;
        while (pos > 0) {
            ans.push_back(dp[pos]);
            pos -= a[dp[pos]-1];
        }
        cout << ans.size() << endl;
        rep(i, ans.size()) cout << ans[i] << ' ';
        cout << endl;
    }
}
