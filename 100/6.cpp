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
    ll n;
    string s;
    cin >> n >> s;

    ll ans = 0;

    rep(i, 10) rep(j, 10) rep(k, 10) {
        ll c = 0;

        rep(l, s.size()) {
            if (c == 0 && s[l] - '0' == i) c++;
            else if (c == 1 && s[l] - '0' == j) c++;
            else if (c == 2 && s[l] - '0' == k) {
                c++;
                break;
            }
        }

        if (c == 3) ans++;
    }

    cout << ans << endl;
}