#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    string n;
    ll k;
    cin >> n >> k;

    rep(l, k) {
        ll n10 = 0;
        rep(i, n.size()) {
            n10 = n10 * 8 + int(n[i] - '0');
        }

        string n9;
        if (n10 == 0) n9 = "0";
        while (n10 > 0) {
            if (n10 % 9 == 8) n9 = '5' + n9;
            else n9 = char(n10 % 9 + '0') + n9;
            n10 /= 9;
        }

        n = n9;
    }

    cout << n << endl;
}