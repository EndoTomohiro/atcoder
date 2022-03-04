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

// 幅優先探索
// 入力：グラフ graph と、探索の始点 s
// 出力：s から各頂点への最短距離を表す配列
void bfs(vvl graph, vl c) {
    ll n = graph.size(); // 頂点数
    vb used(n); // 全頂点を「未訪問」に初期化
    queue<ll> que;

    // 初期条件
    used[0] = true;
    que.push(0);

    // BFS開始（キューが空になるまで探索を行う）
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v からたどれる頂点を全て調べる
        for (ll x : graph[v]) {
            // すでに発見済みの頂点は探索しない
            if (used[x]) continue;

            // 未発見の頂点 x について距離情報を更新してキューに挿入
            c[x] += c[v];
            used[x] = true;
            que.push(x);
        }
    }

    rep(i, n) cout << c[i] << ' ';
    cout << endl;
}

int main() {
    ll n, q;
    cin >> n >> q;
    vvl graph(n, vl(0));
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vl c(n);
    rep(i, q) {
        ll p, x;
        cin >> p >> x;
        c[p - 1] += x;
    }

    bfs(graph, c);
}
