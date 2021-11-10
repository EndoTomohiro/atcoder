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

vl ans;

int bfs(int w, int h, vvl vech, vvl vecw, vvl graph, queue< pair<int, int> > que) {
    while (que.size() > 0 && graph[h-1][w-1] == -1) {
        pair<int, int> p = que.front();
        int pf = p.first;
        int ps = p.second;
        int graphp = graph[pf][ps];
        que.pop();

        if (pf+1 < h && graph[pf+1][ps] == -1 && !vecw[pf][ps]) {
            graph[pf+1][ps] = graphp + 1;
            que.push({pf+1, ps});
        }

        if (ps+1 < w && graph[pf][ps+1] == -1 && !vech[pf][ps]) {
            graph[pf][ps+1] = graphp + 1;
            que.push({pf, ps+1});
        }

        if (pf > 0 && graph[pf-1][ps] == -1 && !vecw[pf-1][ps]) {
            graph[pf-1][ps] = graphp + 1;
            que.push({pf-1, ps});
        }

        if (ps > 0 && graph[pf][ps-1] == -1 && !vech[pf][ps-1]) {
            graph[pf][ps-1] = graphp + 1;
            que.push({pf, ps-1});
        }
    }

    if (graph[h-1][w-1] == -1) return 0;
    else return graph[h-1][w-1];
}

int main() {
    int w, h;
    cin >> w >> h;

    while (w != 0 || h != 0) {
        vvl vech(h, vl(w-1)), vecw(h-1, vl(w));
        rep(i, h-1) {
            rep(j, w-1) cin >> vech[i][j];
            rep(j, w) cin >> vecw[i][j];
        }
        rep(j, w-1) cin >> vech[h-1][j];

        vvl graph(h, vl(w, -1));
        graph[0][0] = 1;
        queue< pair<int, int> > que;
        que.push({0, 0});
        ans.push_back(bfs(w, h, vech, vecw, graph, que));



        cin >> w >> h;
    }

    rep(i, ans.size()) cout << ans[i] << endl;
}