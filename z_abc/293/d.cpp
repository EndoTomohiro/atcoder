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
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
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

    ll ans1 = 0;
    UnionFind uf;
    uf.init(n);
    rep(i, m) {
        ll a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        if (uf.issame(a, c)) ans1++;
        else uf.unite(a, c);
    }

    vl vec(n);
    rep(i, n) vec[i] = uf.root(i);
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    ll ans2 = vec.size() - ans1;

    cout << ans1 << ' ' << ans2 << endl;
}
