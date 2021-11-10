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

int main() {
    ll n, k;
    cin >> n >> k;

    vl c(5010);
    vl r(5010);
    rep(i, n) cin >> c[i] >> r[i];

    vvl road(n, vl(0));
    rep(j, k) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    vvp graph(n, vp(0));
    rep(i, n) {
        vl dist(n, -1);
        queue<ll> que;
        dist[i] = 0;
        que.push(i);

        while (!que.empty()) {
            ll start = que.front();
            que.pop();
            if (dist[start] == r[i]) break;

            for (ll town : road[start]) {
                if (dist[town] != -1) continue;
                dist[town] = dist[start] + 1;
                que.push(town);
            }
        }

        rep(j, n) {
            if (dist[j] != -1) graph[i].push_back({j, c[i]});
        }
    }

    vb used(n, false);
    vl dist(n, INF);
    dist[0] = 0;

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

    cout << dist[n-1] << endl;
}