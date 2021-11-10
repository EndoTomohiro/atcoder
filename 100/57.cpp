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

int n, k;

ll cheapest(ll a, ll b, vvp graph) {
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
    cin >> n >> k;

    vvp graph(n, vp(0));
    vl ans(0);
    rep(i, k) {
        int x;
        cin >> x;

        if (x == 0) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            ans.push_back(cheapest(a, b, graph));
        }

        else {
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            graph[c].push_back({d, e});
            graph[d].push_back({c, e});
        }
    }

    for (ll e : ans) cout << e << endl;
}