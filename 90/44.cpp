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
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl ans;
    ll cnt = 0;

    rep(i, q) {
        ll t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            ll xn = (x - 1 - cnt) % n;
            ll yn = (y - 1 - cnt) % n;
            if (xn < 0) xn += n;
            if (yn < 0) yn += n;
            swap(a[xn], a[yn]);
        }

        else if (t == 2) cnt++;

        else {
            ll xn = (x - 1 - cnt) % n;
            if (xn < 0) xn += n;
            ans.push_back(a[xn]);
        }
    }

    rep(i, ans.size()) cout << ans[i] << endl;
}