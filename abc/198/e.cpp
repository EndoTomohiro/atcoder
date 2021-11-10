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
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
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

vl c(100010);
vl cnt(100010);
vl good(100010);
vvl graph(100010);
vb seen(100010, false);

// 深さ優先探索
void dfs(ll v) {
    seen[v] = true;
    if (cnt[c[v]] == 0) good[v] = true;
    cnt[c[v]]++;

    // v から行ける各頂点 next_v について
    for (auto next_v : graph[v]) {
        if (!seen[next_v]) dfs(next_v); // 再帰的に探索
    }

    cnt[c[v]]--;
}

int main() {
    // 頂点数と辺数
    ll n;
    cin >> n;

    rep(i, n) cin >> c[i];

    // グラフ入力受取（ここでは有向グラフを想定）
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);

    rep(i, n) {
        if (good[i]) cout << i + 1 << endl;
    }
}