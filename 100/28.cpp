#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

queue<int> que;
vector<int> dist(105, -1);
vector<int> k(105);
vector< vector<int> > graph(105, vector<int>(0));

vector<int> bfs(queue<int> que, vector<int> dist, vector<int> k, vector< vector<int> > graph) {
    if (que.size() == 0) return dist;

    int x = que.front();
    que.pop();

    rep(i, k[x]) {
        int a = graph[x][i];
        if (dist[a] == -1) {
            dist[a] = dist[x] + 1;
            que.push(a);
        }
    }

    return bfs(que, dist, k, graph);
}

int main() {
    int n;
    cin >> n;

    rep2(i, n) {
        cin >> i >> k[i];
        vector<int> graphi(k[i]);
        rep(j, k[i]) {
            cin >> graphi[j];
        }
        graph[i] = graphi;
    }

    que.push(1);
    dist[1] = 0;

    vector<int> ans = bfs(que, dist, k, graph);

    rep2(i, n) cout << i << ' ' << ans[i] << endl;
}