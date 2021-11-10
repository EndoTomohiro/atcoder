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

// 入力：グラフ graph と、探索の始点 s
// 出力：s から各頂点への最短経路を表す配列
vl bfs(vvl graph, ll s) {
    ll n = graph.size(); // 頂点数
    vl dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件（頂点０を初期頂点とする）
    dist[s] = 0;
    que.push(s);

    // BFS開始（キューが空になるまで探索を行う）
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v からたどれる頂点を全て調べる
        for (ll x : graph[v]) {
            // すでに発見済みの頂点は探索しない
            if (dist[x] != -1) continue;

            // 未発見の頂点 x について距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    return dist;
}

int main() {
    // 頂点数
    ll n;
    cin >> n;

    // グラフ入力受取
    vvl graph(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 探索
    // 頂点０を始点としたBFS
    vl dist1 = bfs(graph, 0);

    ll max_i = -1;
    ll max_v = -1;
    rep(i, n) {
        if (dist1[i] > max_v) {
            max_i = i;
            max_v = dist1[i];
        }
    }

    vl dist2 = bfs(graph, max_i);

    max_i = -1, max_v = -1;
    rep(i, n) {
        if (dist2[i] > max_v) {
            max_i = i;
            max_v = dist2[i];
        }
    }

    cout << max_v + 1 << endl;
}