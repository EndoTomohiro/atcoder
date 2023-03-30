#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vp = vector< pair<ll, ll> >;
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
    ll a, b, w;
    cin >> a >> b >> w;

    w *= 1000;

    ll aa = 0, bb = 0, mi, ma;
    ll c = 0;
    bool ok = true;

    while (aa <= w - a) {
        c++;
        aa += a, bb += b;

        if (w >= aa && w <= bb && ok) {
            mi = c;
            ok = false;
        }
    }

    if (ok) {
        puts("UNSATISFIABLE");
        return 0;
    }

    ma = c;

    cout << mi << ' ' << ma << endl;

}