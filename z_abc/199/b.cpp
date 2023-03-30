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
    int n;
    cin >> n;
    int a_max = 1;
    int b_min = 1000;
    rep(i, n) {
        int a_i;
        cin >> a_i;
        chmax(a_max, a_i);
    }
    rep(i, n) {
        int b_i;
        cin >> b_i;
        chmin(b_min, b_i);
    }

    if (a_max > b_min) puts("0");
    else cout << b_min - a_max + 1 << endl;
}