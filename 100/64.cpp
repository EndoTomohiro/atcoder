#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (long long)(s); i < (long long)(n); i++)
#define rep3(i, s, n) for (long long i = (long long)(n); i >= (long long)(s); i--)
const long long INF = 1000000000000000;
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

// Union-Find
struct UnionFind {
    vector<long long> par, siz;

    // 初期化
    UnionFind(long long n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    long long root(long long x) {
        if (par[x] == -1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(long long x, long long y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(long long x, long long y) {
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
    long long size(long long x) {
        return siz[root(x)];
    }
};

int main() {
    long long n, m; // 頂点数と辺数
    cin >> n >> m;
    vector< pair<long long, pair<long long, long long> > > edges(m); // 辺集合
    rep(i, m) {
        long long u, v, w; // w は重み
        cin >> u >> v >> w;
        // u--; v--;
        edges[i] = pair<long long, pair<long long, long long> >(w, make_pair(u, v));
    }

    // 各辺を、辺の重みが小さい順にソートする
    // pair はデフォルトで（第一要素、第二要素）の辞書順比較
    sort(all(edges));


    // クラスカル法
    long long res = 0;
    UnionFind uf(n);
    rep(i, m) {
        long long w = edges[i].first;
        long long u = edges[i].second.first;
        long long v = edges[i].second.second;

        // 辺（u, v）の追加によってサイクルが形成される時は追加しない
        if (uf.issame(u, v)) continue;

        // 辺（u, v）を追加する
        res += w;
        uf.unite(u, v);
    }

    cout << res << endl;
}