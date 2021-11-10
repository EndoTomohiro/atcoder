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
    ll n, m, k;
    cin >> n >> m >> k;

    vl a(n+1), b(m+1);
    rep2(i, n) {
        cin >> a[i];
        if (i) a[i] += a[i-1];
    }
    rep2(i, m) {
        cin >> b[i];
        if (i) b[i] += b[i-1];
    }

    ll ans = 0;
    ll j = m;

    rep(i, n+1) {
        while (j >= 0 && a[i] + b[j] > k) {
            j--;
        }
        if (j < 0) break;
        chmax(ans, i + j);
    }

    cout << ans << endl;
}