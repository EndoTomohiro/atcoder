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

queue< pair<int, int> > que;

int bfs(int h, int w, vs str, vvl graph, queue< pair<int, int> > que) {
    while (que.size() > 0 && graph[h-1][w-1] == -1) {
        pair<int, int> p = que.front();
        int pf = p.first;
        int ps = p.second;
        int graphp = graph[pf][ps];
        que.pop();

        if (pf+1 < h && graph[pf+1][ps] == -1 && str[pf+1][ps] == '.') {
            graph[pf+1][ps] = graphp + 1;
            que.push({pf+1, ps});
        }

        if (ps+1 < w && graph[pf][ps+1] == -1 && str[pf][ps+1] == '.') {
            graph[pf][ps+1] = graphp + 1;
            que.push({pf, ps+1});
        }

        if (pf > 0 && graph[pf-1][ps] == -1 && str[pf-1][ps] == '.') {
            graph[pf-1][ps] = graphp + 1;
            que.push({pf-1, ps});
        }

        if (ps > 0 && graph[pf][ps-1] == -1 && str[pf][ps-1] == '.') {
            graph[pf][ps-1] = graphp + 1;
            que.push({pf, ps-1});
        }
    }

    return graph[h-1][w-1];

}

int main() {
    int h, w;
    cin >> h >> w;
    vs str(h);
    rep(i, h) cin >> str[i];

    int ans = -2;
    rep(i, h) rep(j, w) {
        if (str[i][j] == '.') ans++;
    }

    vvl graph(h, vl(w, -1));
    que.push({0, 0});

    int x = bfs(h, w, str, graph, que);

    if (x == -1) cout << -1 << endl;

    else {
        ans -= x;
        cout << ans << endl;
    }
}