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
using Edge2 = pair<pair<ll, ll>, pair<ll, ll> >;

int main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges1(m); // 辺集合
    rep(i, m) {
        ll u, v, w; // w は重み
        cin >> u >> v >> w;
        u--; v--;
        edges1[i] = Edge(w, make_pair(u, v));
    }
    sort(all(edges1));

    vector<Edge2> edges2(q); // 辺集合
    rep(i, q) {
        ll u, v, w; // w は重み
        cin >> u >> v >> w;
        u--; v--;
        edges2[i] = Edge2(make_pair(w, i), make_pair(u, v));
    }
    sort(all(edges2));

    // クラスカル法
    ll r1 = 0, r2 = 0;
    vb ans(q);
    UnionFind uf(n);
    while (r2 < q) {
        if (r1 < m && edges1[r1].first < edges2[r2].first.first) {
            ll w = edges1[r1].first;
            ll u = edges1[r1].second.first;
            ll v = edges1[r1].second.second;

            // 辺（u, v）を追加する
            if (!uf.issame(u, v)) uf.unite(u, v);
            r1++;
        }
        else {
            ll w = edges2[r2].first.first;
            ll i = edges2[r2].first.second;
            ll u = edges2[r2].second.first;
            ll v = edges2[r2].second.second;

            // 辺（u, v）を追加する
            if (!uf.issame(u, v)) ans[i] = true;
            r2++;
        }
    }

    rep(i, q) {
        if (ans[i]) puts("Yes");
        else puts("No");
    }
}
