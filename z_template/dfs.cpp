#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
#define pi 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

// 深さ優先探索
vb seen(100010);
vvl graph(100010);
void dfs(ll v) {
    seen[v] = true; // v を訪問済みにする

    // v から行ける各頂点 next_v について
    for (auto next_v : graph[v]) {
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        dfs(next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    ll n, m;
    cin >> n >> m;

    // グラフ入力受取（ここでは有向グラフを想定）
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        // a--; b--;
        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    // 探索
    seen.assign(n, false); // 初期状態では前頂点が未訪問
    rep(v, n) {
        if (seen[v]) continue; // すでに訪問済みなら探索しない
        dfs(v);
    }
}