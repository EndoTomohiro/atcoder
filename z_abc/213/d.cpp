#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
using vq = vector< queue<ll> >;
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

int main() {
    int n;
    cin >> n;

    vvl graph2(n+1, vl(0));
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }

    rep2(i, 1, n+1) sort(all(graph2[i]));

    vq graph(n+1);
    rep2(i, 1, n+1) rep(j, graph2[i].size()) graph[i].push(graph2[i][j]);

    vb dist(n+1, false);
    dist[1] = true;
    vl vec(1, 1);
    vl ans(1, 1);

    while (true) {
        bool tf = false;
        ll now = ans[ans.size()-1];
        while (!graph[now].empty()) {
            ll city = graph[now].front();
            graph[now].pop();
            if (!dist[city]) {
                tf = true;
                dist[city] = true;
                ans.push_back(city);
                vec.push_back(city);
                break;
            }
        }
        if (tf) continue;
        if (now == 1) break;
        vec.pop_back();
        ans.push_back(vec[vec.size()-1]);
    }

    rep(i, ans.size()) cout << ans[i] << ' ';
    cout << endl;
}