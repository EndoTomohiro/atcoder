#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvb = vector<vb>;
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
    ll n, x;
    cin >> n >> x;
    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vb dp(x+1);
    dp[0] = true;
    vl ok = {0};
    rep(i, n) {
        ll m = ok.size();
        rep(j, m) {
            ll sum = ok[j];
            rep(k, b[i]) {
                sum += a[i];
                if (sum > x) break;
                if (!dp[sum]) {
                    dp[sum] = true;
                    ok.push_back(sum);
                }
            }
        }
    }
    
    if (dp[x]) puts("Yes");
    else puts("No");
}
