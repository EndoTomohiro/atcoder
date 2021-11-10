#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
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

vs graph(1005);
vp pos(1005);
vvl dist(1005, vl(1005, -1));
int h, w;

int bfs(vs graph, queue< pair<int, int> > que, vvl dist, pl g) {

    pair<int, int> p = que.front();
    int pf = p.first;
    int ps = p.second;
    int gf = g.first;
    int gs = g.second;
    int distp = dist[pf][ps];
    que.pop();

    while (dist[gf][gs] == -1) {
        if (pf > 0 && dist[pf-1][ps] == -1 && graph[pf-1][ps] != 'X') {
            dist[pf-1][ps] = distp + 1;
            que.push({pf-1, ps});
        }

        if (pf + 1 < h && dist[pf+1][ps] == -1 && graph[pf+1][ps] != 'X') {
            dist[pf+1][ps] = distp + 1;
            que.push({pf+1, ps});
        }
        if (ps > 0 && dist[pf][ps-1] == -1 && graph[pf][ps-1] != 'X') {
            dist[pf][ps-1] = distp + 1;
            que.push({pf, ps-1});
        }
        if (ps + 1 < w && dist[pf][ps+1] == -1 && graph[pf][ps+1] != 'X') {
            dist[pf][ps+1] = distp + 1;
            que.push({pf, ps+1});
        }

        if (que.size() == 0) continue;

        p = que.front();
        pf = p.first;
        ps = p.second;
        gf = g.first;
        gs = g.second;
        distp = dist[pf][ps];
        que.pop();
    }

    return dist[gf][gs];
}

int main() {
    int n;
    cin >> h >> w >> n;
    rep(i, h) {
        string graphi;
        cin >> graphi;
        graph[i] = graphi;
    }

    rep(i, h) rep(j, w) {
        if (graph[i][j] == 'S') pos[0] = {i, j};
        else if (graph[i][j] != '.') pos[graph[i][j] - '0'] = {i, j};
    }

    int ans = 0;
    rep(i, n) {
        queue< pair<int, int> > que;
        que.push(pos[i]);
        dist[pos[i].first][pos[i].second] = 0;
        ans += bfs(graph, que, dist, pos[i+1]);
    }

    cout << ans << endl;
}