#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
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
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (x <= y) cout << min(a + b, 2 * c) * x + min(b, 2 * c) * (y - x) << endl;
    else cout << min(a + b, 2 * c) * y + min(a, 2 * c) * (x - y) << endl;
}