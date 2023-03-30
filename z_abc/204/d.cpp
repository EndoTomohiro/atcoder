#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
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
    cin >> n;

    vl a(n);
    ll suma = 0;
    rep(i, n) {
        cin >> a[i];
        suma += a[i];
    }

    vvl dp(n+1, vl(100001));
    dp[0][0] = 1;

    rep2(i, n) {
        rep3(j, a[i-1], 100001) dp[i][j] = dp[i-1][j-a[i-1]];
        rep(j, 100001) chmax(dp[i][j], dp[i-1][j]);
    }

    ll ans = suma;
    rep(i, 100001) {
        if (dp[n][i]) chmin(ans, max(i, (suma - i)));
    }

    cout << ans << endl;
}