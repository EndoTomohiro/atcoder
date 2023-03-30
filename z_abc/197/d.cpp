#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
double pi = 3.14159265359;
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
    ll n;
    cin >> n;

    double x0, y0, x2, y2;
    cin >> x0 >> y0 >> x2 >> y2;

    double xc = (x0 + x2) / 2, yc = (y0 + y2) / 2;

    x0 -= xc; x2 -= xc; y0 -= yc; y2 -= yc;

    double x1 = x0 * cos(2 * pi / n) - y0 * sin(2 * pi / n) + xc;
    double y1 = x0 * sin(2 * pi / n) + y0 * cos(2 * pi / n) + yc;

    cout << fixed << setprecision(11);

    cout << x1 << ' ' << y1 << endl;
}