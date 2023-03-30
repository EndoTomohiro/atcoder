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
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
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

ll h, w;

// 幅優先探索
// 入力：グラフ graph と、探索の始点 s
// 出力：s から各頂点への最短距離を表す配列
ll bfs(vs graph, ll i, ll j) {
    vvl dist(h, vl(w, -1)); // 全頂点を「未訪問」に初期化
    queue<pl> que;

    // 初期条件
    dist[i][j] = 0;
    ll cnt = 0;
    que.push(make_pair(i, j));

    // BFS開始（キューが空になるまで探索を行う）
    while (!que.empty()) {
        ll vi = que.front().first; // キューから先頭頂点を取り出す
        ll vj = que.front().second; // キューから先頭頂点を取り出す
        que.pop();

        if (vi < h - 1 && graph[vi + 1][vj] == '.' && dist[vi + 1][vj] == -1) {
            dist[vi + 1][vj] = dist[vi][vj] + 1;
            chmax(cnt, dist[vi + 1][vj]);
            que.push(make_pair(vi + 1, vj));
        } 
        if (vj < w - 1 && graph[vi][vj + 1] == '.' && dist[vi][vj + 1] == -1) {
            dist[vi][vj + 1] = dist[vi][vj] + 1;
            chmax(cnt, dist[vi][vj + 1]);
            que.push(make_pair(vi, vj + 1));
        } 
        if (vi > 0 && graph[vi - 1][vj] == '.' && dist[vi - 1][vj] == -1) {
            dist[vi - 1][vj] = dist[vi][vj] + 1;
            chmax(cnt, dist[vi - 1][vj]);
            que.push(make_pair(vi - 1, vj));
        } 
        if (vj > 0 && graph[vi][vj - 1] == '.' && dist[vi][vj - 1] == -1) {
            dist[vi][vj - 1] = dist[vi][vj] + 1;
            chmax(cnt, dist[vi][vj - 1]);
            que.push(make_pair(vi, vj - 1));
        } 
    }

    return cnt;
}

int main() {
    cin >> h >> w;
    vs graph(h);
    rep(i, h) cin >> graph[i];

    ll ans = 0;
    rep(i, h) rep(j, w) {
        if (graph[i][j] == '.') chmax(ans, bfs(graph, i, j));
    }
    cout << ans << endl;
}
