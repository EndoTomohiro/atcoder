#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vd = vector<double>;
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

    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll l = 0, r = n - 1;
    double tl = 0.0, tr = 0.0;
    double ans = 0;

    rep(i, n-1) {
        double sl = double(a[l]) / b[l];
        double sr = double(a[r]) / b[r];

        if (tl + sl <= tr + sr) {
            ans += a[l];
            l++;
            tl += sl;
        }
        else {
            r--;
            tr += sr;
        }
    }

    if (tl <= tr) {
        double d = b[l] * (tr - tl);
        ans += d + double(a[l] - d) / 2;
    }
    else {
        double d = b[l] * (tl - tr);
        ans += double(a[l] - d) / 2;
    }

    cout << fixed << setprecision(11);
    cout << ans << endl;
}