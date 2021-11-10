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
    void issame(long long x, long long y) {
        bool tf = root(x) == root(y);
        if (tf) cout << 1 << endl;
        else cout << 0 << endl;
    }

    // x を含むグループと y を含むグループとを併合する
    void unite(long long x, long long y) {
        // x, y をそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループの時は何もしない
        if (x == y) return;

        // union by side（y 側のサイズが小さくなるようにする）
        if (siz[x] < siz[y]) swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
    }

    // x を含むグループのサイズ
    long long size(long long x) {
        return siz[root(x)];
    }
};

int main() {
    long long n, q;
    cin >> n >> q;

    UnionFind uf(n);

    vector<int> com(q), x(q), y(q);

    rep(i, q) {
        cin >> com[i] >> x[i] >> y[i];
    }

    rep(i, q) {
        if (com[i] == 0) uf.unite(x[i], y[i]);
        else uf.issame(x[i], y[i]);
    }
}