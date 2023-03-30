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
const ll inf = 1000000000000000;
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
    vb hit(4, false);
    rep(i, 4) {
        string s;
        cin >> s;
        if (s == "H") hit[0] = true;
        else if (s == "2B") hit[1] = true;
        else if (s == "3B") hit[2] = true;
        else hit[3] = true;
    }

    if (hit[0] && hit[1] && hit[2] && hit[3]) puts("Yes");
    else puts("No");
}