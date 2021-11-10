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
    ll n;
    cin >> n;

    ll amari = n % 3;
    ll keta = 0;

    ll c1 = 0, c2 = 0;
    while (n > 0) {
        ll x = n % 10 % 3;
        if (x == 1) c1++;
        else if (x == 2) c2++;
        n /= 10;
        keta++;
    }

    if (amari == 0) cout << 0 << endl;

    else if (((amari == 1 && c1 >= 1) || amari == 2 && c2 >= 1) && keta > 1) {
        cout << 1 << endl;
    }

    else if (((amari == 1 && c1 == 0 && c2 >= 2) || amari == 2 && c1 >= 2 && c2 == 0) && keta > 2) {
        cout << 2 << endl;
    }

    else cout << -1 << endl;
}