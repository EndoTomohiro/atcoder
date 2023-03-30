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
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vl a(m), b(m), c(m);
    vvl dp(n, vl(n, INF));

    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;

        dp[a[i]][b[i]] = c[i];
        dp[b[i]][a[i]] = c[i];
    }
    //rep(i, n) dp[i][i] = 0;

    rep(k, n) rep(i, n) rep(j, n) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    ll ans = 0;
    rep(i, m) {
        bool unused = false;
        rep(j, n) {
            if (dp[a[i]][j] + dp[j][b[i]] <= c[i]) {
                unused = true;
                break;
            }
        }
        if (unused) ans++;
    }
    cout << ans << endl;
}
