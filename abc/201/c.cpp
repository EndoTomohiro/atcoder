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
    string s;
    cin >> s;
    int maru = 0, batu = 0, hatena = 0;
    rep(i, 10) {
        if (s[i] == 'o') maru++;
        else if (s[i] == 'x') batu++;
        else hatena++;
    }

    ll c1 = hatena;
    ll c2 = hatena * (hatena - 1) / 2;
    ll c3 = hatena * (hatena - 1) * (hatena - 2) / 6;
    ll c4 = hatena * (hatena - 1) * (hatena - 2) * (hatena - 3) / 24;

    if (maru == 4) cout << 24 << endl;
    else if (maru == 3) cout << c1 * 24 + 3 * 12 << endl;
    else if (maru == 2) cout << c2 * 24 + c1 * 3 * 12 + 2 * 4 + 6 << endl;
    else if (maru == 1) cout << c3 * 24 + c2 * 3 * 12 + c1 * (2 * 4 + 6) + 1 << endl;
    else if (maru == 0) cout << c4 * 24 + c3 * 3 * 12 + c2 * (2 * 4 + 6) + c1 << endl;
    else cout << 0 << endl;
}