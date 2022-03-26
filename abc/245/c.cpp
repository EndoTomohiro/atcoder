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
    void init(ll sz) {
		par.resize(sz, -1);
        siz.resize(sz, 1);
	}

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
    ll n, k;
    cin >> n >> k;
    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    UnionFind uf;
    uf.init(2 * n);
    rep(i, n - 1) {
        if (abs(a[i] - a[i + 1]) <= k) uf.unite(i * 2, (i + 1) * 2);
        if (abs(b[i] - b[i + 1]) <= k) uf.unite(i * 2 + 1, (i + 1) * 2 + 1);
        if (abs(a[i] - b[i + 1]) <= k) uf.unite(i * 2, (i + 1) * 2 + 1);
        if (abs(b[i] - a[i + 1]) <= k) uf.unite(i * 2 + 1, (i + 1) * 2);
    }
    if (uf.issame(0, (n - 1) * 2) || uf.issame(0, (n - 1) * 2 + 1) || uf.issame(1, (n - 1) * 2) || uf.issame(1, (n - 1) * 2 + 1)) {
        puts("Yes");
    }
    else puts("No");
}
