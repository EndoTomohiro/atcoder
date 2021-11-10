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

ll powx(int a, ll n) {
    ll pow = 1;
    rep(i, n) {
        pow *= a;
    }
    return pow;
}

int main() {
    ll n;
    cin >> n;

    for (ll i = 1; ; i++) {
        if (stoll(to_string(i) + to_string(i)) > n) {
            cout << i - 1 << endl;
            return 0;
        }
    }
}