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

ll comp2(vl a, vl b) {
    return a[2] < b[2];
}

ll comp3(vl a, vl b) {
    return a[3] < b[3];
}

int main() {
    ll n;
    cin >> n;

    vvl vec(n, vl(4));

    rep(i, n) {
        ll x, y;
        cin >> x >> y;

        vec[i][0] = x;
        vec[i][1] = y;
        vec[i][2] = x + y;
        vec[i][3] = x - y;
    }

    ll ans = 0;

    sort(all(vec), comp2);
    chmax(ans, abs(vec[0][0] - vec[n-1][0]) + abs(vec[0][1] - vec[n-1][1]));

    sort(all(vec), comp3);
    chmax(ans, abs(vec[0][0] - vec[n-1][0]) + abs(vec[0][1] - vec[n-1][1]));

    cout << ans << endl;
}