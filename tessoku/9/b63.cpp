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
using dl = deque<pl>;
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

vvl dist(60, vl(60, -1));
vs graph(60);
ll r, c, sy, sx, gy, gx;

vvl bfs(ll sy, ll sx) {
    // 初期条件
    dl que;
    que.push_back({sy, sx});

    // BFS開始（キューが空になるまで探索を行う）
    while (!que.empty()) {
        ll y = que.front().first; // キューから先頭頂点を取り出す
        ll x = que.front().second;
        que.pop_front();

        vl dy = {-1, 0, 0, 1};
        vl dx = {0, -1, 1, 0};

        // v からたどれる頂点を全て調べる
        rep(i, 4) {
            ll ny = y + dy[i];
            ll nx = x + dx[i];
            if (dist[ny][nx] != -1 || graph[ny][nx] != '.' || ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push_back({ny, nx});
        }
    }

    return dist;
}

int main() {
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    rep(i, r) cin >> graph[i];
    dist[sy][sx] = 0;
    vvl ans = bfs(sy, sx);
    cout << ans[gy][gx] << endl;
}