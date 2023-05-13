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
using ml = map<char, ll>;
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
    ml maps, mapt;
    rep(i, s.size()) {
        maps[s[i]]++;
        mapt[t[i]]++;
    }

    ll u = 0, v = 0;
    rep(i, 26) {
        char c = 'a' + char(i);
        if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r') {
            if (maps[c] < mapt[c]) u += mapt[c] - maps[c];
            else v += maps[c] - mapt[c];
        }
        else if (maps[c] != mapt[c]) {
            puts("No");
            return 0;
        }
    }
    if (u <= maps['@'] && v <= mapt['@']) puts("Yes");
    else puts("No");
}
