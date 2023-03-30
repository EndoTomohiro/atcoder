#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<string, ll>;
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

bool comp(pl a, pl b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ll n;
    cin >> n;
    vp vec(n);
    rep(i, n) cin >> vec[i].first >> vec[i].second;

    vp vec2 = vec;
    sort(all(vec2), comp);
    rep(i, n) rep(j, n) {
        if (vec2[i] == vec[j]) cout << j + 1 << endl;
    }
}
