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
    ll w; // 重み
    Edge(ll to, ll w) : to(to), w(w) {}
};

using ve = vector<Edge>;
using vve = vector<ve>;

int main() {
    // 頂点数、変数、始数
    ll n, m;
    cin >> n >> m;

    // グラフ
    vve g(n);
    rep(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back(Edge(b, w));
        g[b].push_back(Edge(a, w));
    }

    // ダイクストラ法
    vl dist(n, INF), before(n, -1);
    dist[0] = 0;

    // (d[v], v) のペアを要素としたヒープを作る
    priority_queue< pl, vp, greater<pl> > que;
    que.push(make_pair(dist[0], 0));

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
            if (chmin(dist[e.to], dist[v] + e.w)) {
                // 更新があるならヒープに新たに挿入
                que.push(make_pair(dist[e.to], e.to));
                before[e.to] = v;
            }
        }
    }

    vl ans;
    ll v = n - 1;
    while (true) {
        ans.push_back(v + 1);
        if (v == 0) break;
        v = before[v];
    }
    reverse(all(ans));
    rep(i, ans.size()) cout << ans[i] << ' ';
    cout << endl;
}