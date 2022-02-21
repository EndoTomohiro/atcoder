#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

vvl graph(200010, vl(0));
vl vec(0);
vb seen(200010);

// 幅優先探索
// 深さ優先探索
void dfs(ll v) {
    seen[v] = true; // v を訪問済みにする
    vec.push_back(v);

    // v から行ける各頂点 next_v について
    for (auto next_v : graph[v]) {
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        dfs(next_v); // 再帰的に探索
    }
}

int main() {
    ll n;
    cin >> n;
    rep(i, n - 1) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0);

    vl l(n, INF), r(n, -INF);
    vb used(n);
    ll cnt = 1;
    rep4(i, 0, n - 1) {
        ll v = vec[i];
        used[v] = true;
        if (v != 0 && graph[v].size() == 1) {
            ll next = graph[v][0];
            l[v] = cnt;
            r[v] = cnt;
            chmin(l[next], l[v]);
            chmax(r[next], r[v]);
            cnt++;
        }
        else {
            rep(j, graph[v].size()) {
                ll next = graph[v][j];
                if (!used[next]) {
                    chmin(l[next], l[v]);
                    chmax(r[next], r[v]);
                    break;
                }
            }
        }
    }

    rep(i, n) cout << l[i] << ' ' << r[i] << endl;
}
