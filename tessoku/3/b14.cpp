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
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, n) cin >> a[i];

    ll m = n / 2, l1 = 1 << m, l2 = 1 << (n-m);
    vl s1(l1), s2(l2);

    rep(i, l1) {
        bitset<20> bit(i);
        rep(j, m) if (bit.test(j)) s1[i] += a[j];
    }
    rep(i, l2) {
        bitset<20> bit(i);
        rep(j, n-m) if (bit.test(j)) s2[i] += a[m+j];
    }
    rep(i, l1) rep(j, l2) {
        if (s1[i] + s2[j] == k) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
