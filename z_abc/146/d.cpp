#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvp = vector<vp>;
using ql = queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using sp = set<pl>;
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

vl ans(100010);
vvp graph(100010, vp(0));

void dfs(ll cu, ll pa = -1, ll col = 0) {
    sl used;
    used.insert(col);
    ll c = 1;
    for (auto to : graph[cu]) {
        if (to.first != pa) {
            while (used.count(c)) c++;
            ans[to.second] = c;
            dfs(to.first, cu, c);
            c++;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
    }

    ll k = 0;
    rep(i, n) chmax(k, ll(graph[i].size()));
    cout << k << endl;

    dfs(0);
    rep(i, n - 1) cout << ans[i] << endl;

}
