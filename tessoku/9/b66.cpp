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
using dl = deque<bool>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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
    ll n, m;
    cin >> n >> m;
    vl a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    ll q;
    cin >> q;
    vl t(q), x(q), u(q), v(q);
    vb canceled(n);
    rep(i, q) {
        cin >> t[i];
        if (t[i] == 1) {
            cin >> x[i];
            x[i]--;
            canceled[x[i]] = true;
        }
        else {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        }
    }

    UnionFind uf;
    uf.init(n);
    rep(i, m) {
        if (!canceled[i]) uf.unite(a[i], b[i]);
    }

    dl que;
    vb ans(q);
    rep(i, q) {
        ll j = q - 1 - i;
        if (t[j] == 1) uf.unite(a[x[j]], b[x[j]]);
        else ans[j] = uf.issame(u[j], v[j]);
    }

    rep(i, q) {
        if (t[i] == 2) {
            if (ans[i]) puts("Yes");
            else puts("No");
        }
    }
}