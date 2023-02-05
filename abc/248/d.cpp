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
    vvl graph(200010, vl(0));
    rep2(i, n) {
        ll a;
        cin >> a;
        graph[a].push_back(i);
    }
    ll q;
    cin >> q;
    vl ans(q);
    rep(i, q) {
        ll l, r, x;
        cin >> l >> r >> x;
        ll less = lower_bound(all(graph[x]), l) - graph[x].begin();
        ll more = graph[x].end() - upper_bound(all(graph[x]), r);
        ans[i] = graph[x].size() - less - more;
    }
    rep(i, q) cout << ans[i] << endl;
}
