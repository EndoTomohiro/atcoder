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
    ll n, m;
    cin >> n >> m;

    vl h(n), w(m);
    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];
    sort(all(h));
    sort(all(w));

    ll ans = INF;
    ll cnt = 0;

    rep(i, n/2) cnt += h[2 * i + 2] - h[2 * i + 1];

    rep(i, n/2 + 1) {
        if (i) {
            cnt += h[2 * i - 1] - h[2 * i - 2];
            cnt -= h[2 * i] - h[2 * i - 1];
        }
        ll less = lower_bound(all(w), h[2 * i]) - w.begin();
        ll tea;
        if (less == m) tea = h[2 * i] - w[m - 1];
        else if (less == 0) tea = w[0] - h[2 * i];
        else tea = min(h[2 * i] - w[less - 1], w[less] - h[2 * i]);
        chmin(ans, cnt + tea);
    }

    cout << ans << endl;
}