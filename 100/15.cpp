#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
using vs = vector<string>;
#define pi 3.14159265359;
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
    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    double ans = 0.0;
    rep(i, n) rep(j, n) {
        double xij = x[i]-x[j];
        double yij = y[i]-y[j];
        double ij = xij * xij + yij * yij;
        ans += sqrt(ij);
    }

    ans /= n;

    cout << fixed << setprecision(10);

    cout << ans << endl;
}