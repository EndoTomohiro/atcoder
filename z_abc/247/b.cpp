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
using ml = map<string, ll>;
using sl = set<ll>;
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
    ll n;
    cin >> n;
    vs v1(n), v2(n);
    ml m1, m2;
    rep(i, n) {
        string s, t;
        cin >> s >> t;
        v1[i] = s;
        v2[i] = t;
        m1[s]++;
        m2[t]++;
    }
    rep(i, n) {
        m1[v1[i]]--; m2[v2[i]]--;
        if (m1[v1[i]] + m2[v1[i]] && m1[v2[i]] + m2[v2[i]]) {
            puts("No");
            return 0;
        }
        m1[v1[i]]++; m2[v2[i]]++;
    }
    puts("Yes");
}
