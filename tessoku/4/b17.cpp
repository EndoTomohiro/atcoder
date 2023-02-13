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
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    vl h(n);
    rep(i, n) cin >> h[i];
    vl dp(n, INF), route(n);
    route[0] = 0;
    dp[0] = 0;
    rep(i, n-1) {
        if (i < n-2) {
            if (chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]))) route[i+2] = i;
        }
        if (chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]))) route[i+1] = i;
    }
    vl ans(0);
    ll pos = n - 1;
    while (pos >= 0) {
        ans.push_back(pos+1);
        if (pos == 0) break;
        pos = route[pos];
    }
    ll k = ans.size();
    cout << k << endl;
    rep(i, k) cout << ans[k-i-1] << ' ';
    cout << endl;
}
