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
    ll n;
    cin >> n;

    if (n < 1000) cout << 0 << endl;
    else if (n < 1000000) cout << n - 999 << endl;
    else if (n < 1000000000) cout << (1000000 - 1000) + 2 * (n - 999999) << endl;
    else if (n < 1000000000000) cout << (1000000 - 1000) + 2 * (1000000000 - 1000000) + 3 * (n - 999999999) << endl;
    else if (n < 1000000000000000) cout << (1000000 - 1000) + 2 * (1000000000 - 1000000) + 3 * (1000000000000 - 1000000000) + 4 * (n - 999999999999) << endl;
    else cout << (1000000 - 1000) + 2 * (1000000000 - 1000000) + 3 * (1000000000000 - 1000000000) + 4 * (1000000000000000 - 1000000000000) + 5 << endl;
}