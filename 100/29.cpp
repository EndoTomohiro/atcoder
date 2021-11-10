#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
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

int main() {
    ll r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vs graph(r);
    rep(i, r) cin >> graph[i];
    
    vvl dist(r, vl(c, -1));
    queue<pl> que;

    dist[sy][sx] = 0;
    que.push({sy, sx});

    while (dist[gy][gx] == -1) {
        pl v = que.front();
        que.pop();

        ll vf = v.first, vs = v.second;
        if (vf > 0 && graph[vf-1][vs] == '.' && dist[vf-1][vs] == -1) {
            dist[vf-1][vs] = dist[vf][vs] + 1;
            que.push({vf-1, vs});
        }
        if (vs > 0 && graph[vf][vs-1] == '.' && dist[vf][vs-1] == -1) {
            dist[vf][vs-1] = dist[vf][vs] + 1;
            que.push({vf, vs-1});
        }
        if (vf < r && graph[vf+1][vs] == '.' && dist[vf+1][vs] == -1) {
            dist[vf+1][vs] = dist[vf][vs] + 1;
            que.push({vf+1, vs});
        }
        if (vs < c && graph[vf][vs+1] == '.' && dist[vf][vs+1] == -1) {
            dist[vf][vs+1] = dist[vf][vs] + 1;
            que.push({vf, vs+1});
        }
    }

    cout << dist[gy][gx] << endl;
}