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
    vs s(n);
    rep(i, n) cin >> s[i];

    vvl graph(10, vl(10));
    rep(i, n) rep(j, 10) {
        ll x = s[i][j] - '0';
        graph[x][j]++;
    }

    vl ans(10);
    rep(i, 10) {
        ll max_range = *max_element(all(graph[i]));
        rep(j, 10) {
            if (graph[i][j] == max_range) {
                ll y = 10 * (max_range - 1) + j;
                chmax(ans[i], y);
            }
        }
    }
    cout << *min_element(all(ans)) << endl;
}
