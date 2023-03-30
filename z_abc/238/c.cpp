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
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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

    ll ans = 0;
    ll bef = 0;
    ll b = 9;
    while (n > bef * 10 + 9) {
        if (b % 2 == 0) {
            ans += ((b + 1) % dif) * (b / 2 % dif) % dif;
            ans %= dif;
        }
        else {
            ans += ((b + 1) / 2 % dif) * (b % dif) % dif;
            ans %= dif;
        }
        bef = bef * 10 + 9;
        b *= 10;
    }

    ll c = n - bef;
    if (c % 2 == 0) {
        ans += ((c + 1) % dif) * (c / 2 % dif) % dif;
        ans %= dif;
    }
    else {
        ans += ((c + 1) / 2 % dif) * (c % dif) % dif;
        ans %= dif;
    }
    cout << ans << endl;
}
