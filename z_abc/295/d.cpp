#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvb = vector<vb>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<vl, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
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
    string s;
    cin >> s;
    ll n = s.size();
    vl vec(10);
    ml mp;
    mp[vec]++;
    rep(i, n) {
        ll t = s[i] - '0';
        vec[t]++;
        vec[t] %= 2;
        mp[vec]++;
    }

    ll ans = 0;
    rep(i, 1 << 10) {
        bitset<10> bit(i);
        ll sum = 0;
        vl vec2(10);
        rep(j, 10) if (bit.test(j)) vec2[j] = 1;
        ans += mp[vec2] * (mp[vec2] - 1) / 2;
    }
    cout << ans << endl;
}
