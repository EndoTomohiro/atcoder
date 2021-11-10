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

bool ok(ll x, ll n, vl h, vl s) {
    vl time(n);
    rep(i, n) {
        if (x < h[i]) {
            return false;
        }
        
        time[i] = (x - h[i]) / s[i];
    }
    sort(all(time));

    rep(i, n) if (time[i] < i) return false;

    return true;
}

ll binary(ll right, ll n, vl h, vl s) {
    ll left = 0;
    while (right >= left) {
        ll mid = left + (right - left) / 2;
        if (left == right && ok(mid, n, h, s)) return mid;
        else if (left == right && !ok(mid, n, h, s)) return mid + 1;
        else if (ok(mid, n, h, s)) right = mid;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    ll n;
    cin >> n;

    vl h(n), s(n);
    rep(i, n) cin >> h[i] >> s[i];

    ll maxh = 0;
    rep(i, n) chmax(maxh, h[i] + s[i] * (n - 1));

    cout << binary(maxh, n, h, s) << endl;
}