#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
using vvp = vector<vp>;
using vs = vector<string>;
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
    double t, l, x, y, q;
    cin >> t >> l >> x >> y >> q;

    vd ans;

    rep(i, q) {
        double e;
        cin >> e;
        double ang = atan((l / 2 * (1 - cos(2 * e * pi / t))) / sqrt(x * x + (y + l / 2 * sin(2 * e * pi / t)) * (y + l / 2 * sin(2 * e * pi / t)))) / pi * 180.0;
        ans.push_back(ang);
    }

    rep(i, q) {
        cout << fixed << setprecision(10);
        cout << ans[i] << endl;
    }
}