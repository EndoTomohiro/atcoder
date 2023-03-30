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

// Union-Find
struct UnionFind {
    vl par, siz;

    // 初期化
    UnionFind(ll n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    ll root(ll x) {
        if (par[x] == -1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(ll x, ll y) {
        // x, y をそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループの時は何もしない
        if (x == y) return false;

        // union by side（y 側のサイズが小さくなるようにする）
        if (siz[x] < siz[y]) swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    ll size(ll x) {
        return siz[root(x)];
    }
};

// 辺 e = (u, v) を {w(e), {u, v}} で表す
using Edge = pair<ll, pair<ll, ll> >;

int main() {
    ll n, m; // 頂点数と辺数
    cin >> n >> m;
    vector<Edge> edges(m); // 辺集合
    rep(i, m) {
        ll u, v, w; // w は重み
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // 各辺を、辺の重みが小さい順にソートする
    // pair はデフォルトで（第一要素、第二要素）の辞書順比較
    sort(all(edges));


    // クラスカル法
    ll res = 0;
    UnionFind uf(n);
    rep(i, m) {
        ll w = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        // 辺（u, v）の追加によってサイクルが形成される時は追加しない
        if (uf.issame(u, v)) {
            if (w > 0) res += w;
            continue;
        }

        // 辺（u, v）を追加する
        uf.unite(u, v);
    }

    cout << res << endl;
}