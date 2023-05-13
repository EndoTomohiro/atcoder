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
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
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
    string s, t;
    cin >> s >> t;
    ll m = s.size();
    ll n = t.size();
    vb left(n+1), right(n+1);
    left[0] = true;
    rep(i, n) {
        if (left[i] && (s[i] == t[i] || s[i] == '?' || t[i] == '?')) {
            left[i+1] = true;
        }
    }
    right[n] = true;
    rep(i, n) {
        if (right[n-i] && (s[m-1-i] == t[n-1-i] || s[m-1-i] == '?' || t[n-1-i] == '?')) {
            right[n-1-i] = true;
        }
    }
    ll ans = 0;
    rep(i, n+1) {
        if (left[i] && right[i]) puts("Yes");
        else puts("No");
    }
}
