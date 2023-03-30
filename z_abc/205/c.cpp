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
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;

    if (a >= 0 && b >= 0) {
        if (a < b) ans--;
        else if (a > b) ans++;
    }
    else if (a >= 0 && b < 0) {
        if (c % 2 == 0 && a < -b) ans--;
        else if (c % 2 == 1 || a > -b) ans++;
    }
    else if (a < 0 && b >= 0) {
        if (c % 2 == 1 || -a < b) ans--;
        else if (c % 2 == 0 && -a > b) ans++;
    }
    else {
        if (c % 2 == 0) {
            if (-a < -b) ans--;
            else if (-a > -b) ans++;
        }
        else {
            if (a < b) ans--;
            else if (a > b) ans++;
        }
    }

    if (ans == -1) cout << '<' << endl;
    else if (ans == 1) cout << '>' << endl;
    else cout << '=' << endl;
}