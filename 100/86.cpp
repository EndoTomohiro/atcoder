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

int main() {
    ll n, m;
    cin >> n >> m;

    vl a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    ll ans = 0;
    rep(i, m) {
        UnionFind uf(n);
        rep(j, m) {
            if (j == i) continue;
            uf.unite(a[j], b[j]);
        }

        ll res = 0;
        rep(x, n) {
            if (uf.root(x) == x) res++;
        }

        if (res > 1) ans++;
    }

    cout << ans << endl;
}