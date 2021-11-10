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

vvl graph(105, vl(105));
vvl tf(105, vl(105));
queue< pair<int, int> > que;

int bfs(int ans, vvl graph, vvl tf, queue< pair<int, int> > que) {
    while (que.size() > 0) {
    pair<int, int> v = que.front();
    int vf = v.first;
    int vs = v.second;
    que.pop();

    if (vs % 2 == 0 && vf > 0 && vs > 0 && graph[vf-1][vs-1]) ans++;
    if (vs % 2 == 0 && vf > 0 && vs > 0 && !graph[vf-1][vs-1] && !tf[vf-1][vs-1]) {
        que.push({vf-1, vs-1});
        tf[vf-1][vs-1] = 1;
    }

    if (vs > 0 && graph[vf][vs-1]) ans++;
    if (vs > 0 && !graph[vf][vs-1] && !tf[vf][vs-1]) {
        que.push({vf, vs-1});
        tf[vf][vs-1] = 1;
    }

    if (vs % 2 != 0 && vf < 104 && vs > 0 && graph[vf+1][vs-1]) ans++;
    if (vs % 2 != 0 && vf < 104 && vs > 0 && !graph[vf+1][vs-1] && !tf[vf+1][vs-1]) {
        que.push({vf+1, vs-1});
        tf[vf+1][vs-1] = 1;
    }

    if (vf > 0 && graph[vf-1][vs]) ans++;
    if (vf > 0 && !graph[vf-1][vs] && !tf[vf-1][vs]) {
        que.push({vf-1, vs});
        tf[vf-1][vs] = 1;
    }

    if (vf < 104 && graph[vf+1][vs]) ans++;
    if (vf < 104 && !graph[vf+1][vs] && !tf[vf+1][vs]) {
        que.push({vf+1, vs});
        tf[vf+1][vs] = 1;
    }

    if (vs % 2 == 0 && vs < 104 && vf > 0 && graph[vf-1][vs+1]) ans++;
    if (vs % 2 == 0 && vs < 104 && vf > 0 && !graph[vf-1][vs+1] && !tf[vf-1][vs+1]) {
        que.push({vf-1, vs+1});
        tf[vf-1][vs+1] = 1;
    }

    if (vs < 104 && graph[vf][vs+1]) ans++;
    if (vs < 104 && !graph[vf][vs+1] && !tf[vf][vs+1]) {
        que.push({vf, vs+1});
        tf[vf][vs+1] = 1;
    }

    if (vs % 2 != 0 && vf < 104 && vs < 104 && graph[vf+1][vs+1]) ans++;
    if (vs % 2 != 0 && vf < 104 && vs < 104 && !graph[vf+1][vs+1] && !tf[vf+1][vs+1]) {
        que.push({vf+1, vs+1});
        tf[vf+1][vs+1] = 1;
    }

    }

    return ans;
}

int main() {
    int w, h;
    cin >> w >> h;
    rep(i, h) rep(j, w) {
        cin >> graph[j+1][i+1];
    }

    que.push({0, 0});
    tf[0][0] = 1;
    int ans = bfs(0, graph, tf, que);
    cout << ans << endl;
}