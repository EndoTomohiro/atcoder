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
const ll dif = 1000000007;
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
    ll t;
    cin >> t;
    vb ans(t);
    rep(o, t) {
        ll a, s;
        cin >> a >> s;
        bitset<65> bit_a(a);
        bitset<65> bit_x(a * 2);
        bitset<65> bit_s(s);
        rep(i, 62) {
            if (!bit_a.test(i) && bit_x.test(i) && !bit_s.test(i)) {
                bit_x.reset(i);
                bit_x.set(i + 1);
            }
            else if (!bit_a.test(i) && !bit_x.test(i) && bit_s.test(i)) {
                bit_x.set(i);
            }
        }
        if (bit_x == bit_s) ans[o] = true;
        else ans[o] = false;
    }
    rep(o, t) {
        if (ans[o]) puts("Yes");
        else puts("No");
    }
}
