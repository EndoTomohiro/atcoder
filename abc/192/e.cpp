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
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// 辺を表す型
struct Edge {
    ll to; // 隣接頂点番号
    ll t; // 重み
    ll k;
    Edge(ll to, ll t, ll k) : to(to), t(t), k(k) {}
};

using ve = vector<Edge>;
using vve = vector<ve>;

int main() {
    // 超点数、変数、始数
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;

    // グラフ
    vve g(n);
    rep(i, m) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        g[a].push_back(Edge(b, t, k));
        g[b].push_back(Edge(a, t, k));
    }

    // ダイクストラ法
    vl dist(n, INF);
    dist[x] = 0;

    // (d[v], v) のペアを要素としたヒープを作る
    priority_queue< pl, vp, greater<pl> > que;
    que.push(make_pair(dist[x], x));

    // ダイクストラ法の反復を開始
    while (!que.empty()) {
        // v: 使用済みでない頂点のうち d[v] が最小の頂点
        // d: v に対するキー値
        ll v = que.top().second;
        ll d = que.top().first;
        que.pop();

        // d > dist[v] は、(d, v) がゴミであることを意味する
        if (d > dist[v]) continue;

        // 頂点 v を始点とした各辺を緩和
        for (auto e : g[v]) {
            if (chmin(dist[e.to], (dist[v] + e.k - 1) / e.k * e.k + e.t)) {
                // 更新があるならヒープに新たに挿入
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // 結果出力
    if (dist[y] < INF) cout << dist[y] << endl;
    else cout << -1 << endl;
}