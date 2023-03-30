#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const double INF = 2000000000.0;
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

bool line(ll a, ll b, ll c, ll d) {
    if (a == 0 || b == 0) return a == 0 && b == 0;
    else return double(c) / a == double(d) / b;
}

int main() {
    ll n;
    cin >> n;

    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vd vec;

    rep(i, n - 1) rep3(j, i + 1, n) {
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        if (dx == 0) vec.push_back(INF);
        else vec.push_back(double(dy) / dx);
    }

    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    cout << vec.size() * 2 << endl;
}