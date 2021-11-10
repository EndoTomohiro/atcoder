#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvp = vector< vector< pair<ll, ll> > >;
using vvl = vector<vl>;
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

int n, m, k, s, p, q;
vvl road(100010, vl(0));
vvp graph(100010, vp(0));
vb zonvi(100010, false);
vl dist(100010, -1);
queue<ll> que;


ll money(int i) {
    if (i == n-1) return 0;
    if (zonvi[i]) return INF;
    if (dist[i] == -1) return p;
    return q;
}

ll cheapest(ll a, ll b) {
    vb used(n, false);
    vl dist(n, INF);
    dist[a] = 0;
    rep(i, n) {
        ll min_dist = INF;
        ll min_j = -1;
        rep(j, n) {
            if (!used[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_j = j;
            }
        }

        if (min_j == -1) break;

        for (pl e : graph[min_j]) chmin(dist[e.first], dist[min_j] + e.second);

        used[min_j] = true;
    }

    if (dist[b] == INF) return -1;
    return dist[b];
}

int main() {
    cin >> n >> m >> k >> s >> p >> q;

    rep(i, k) {
        int x;
        cin >> x;
        zonvi[x-1] = true;
    }

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    rep(i, n) {
        if (zonvi[i]) {
            dist[i] = 0;
            que.push(i);
        }
    }

    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        if (dist[v] == s) break;

        for (ll j : road[v]) {
            if (dist[j] != -1) continue;
            dist[j] = dist[v] + 1;
            que.push(j);
        }
    }

    rep(i, n) {
        for (ll j : road[i]) graph[i].push_back({j, money(j)});
    }

    cout << cheapest(0, n-1) << endl;
}