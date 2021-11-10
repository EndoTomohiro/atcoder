#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
const int INF = 1000000001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rep3(i, s, n) for (int i = (int)(n); i >= (int)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int v, e, r;
    cin >> v >> e >> r;

    vector< vector< pair<int, int> > > graph(v, vector< pair<int, int> >(0));
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({t, d});
    }

    vector<bool> used(v, false);
    vector<int> dist(v, INF);
    dist[r] = 0;
    rep(i, v) {
        int min_dist = INF;
        int min_v = -1;
        rep(j, v) {
            if (!used[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_v = j;
            }
        }

        if (min_v == -1) break;

        rep(e, graph[min_v].size()) chmin(dist[graph[min_v][e].first], dist[min_v] + graph[min_v][e].second);
        // for (pair<int, int> e : graph[min_v]) chmin(dist[e.first], dist[min_v] + e.second);

        used[min_v] = true;
    }

    rep(i, v) {
        if (dist[i] < INF) cout << dist[i] << endl;
        else cout << "INF" << endl;
    }
}