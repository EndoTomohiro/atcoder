#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vs s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;

    int a = x, b = y;
    while (a >= 0 && a < h && b >= 0 && b < w && s[a][b] != '#') {
        ans++;
        a--;
    }

    a = x+1, b = y;
    while (a >= 0 && a < h && b >= 0 && b < w && s[a][b] != '#') {
        ans++;
        a++;
    }

    a = x, b = y-1;
    while (a >= 0 && a < h && b >= 0 && b < w && s[a][b] != '#') {
        ans++;
        b--;
    }

    a = x, b = y+1;
    while (a >= 0 && a < h && b >= 0 && b < w && s[a][b] != '#') {
        ans++;
        b++;
    }

    cout << ans << endl;
}