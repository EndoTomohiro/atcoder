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
using msl = multiset<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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
    ll n, m, x;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    cin >> m;
    vl b(m);
    rep(i, m) cin >> b[i];
    cin >> x;

    vl dp(x+1);
    rep(i, m) dp[b[i]] = -1;
    dp[0] = 1;
    rep2(i, x) rep(j, n) {
        if (i - a[j] >= 0 && dp[i] != -1 && dp[i - a[j]] == 1) dp[i] = 1;
    }

    if (dp[x]) puts("Yes");
    else puts("No");
}
