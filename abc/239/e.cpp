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
using qp = queue<pl>;
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

int main() {
    ll n, q;
    cin >> n >> q;
    vl x(n);
    rep(i, n) cin >> x[i];
    vvl graph(n, vl(0));
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep(i, n) {
        sort(all(graph[i]));
        graph[i].erase(unique(all(graph[i])), graph[i].end());
    }

    vvl dis(n, vl(0));
    dis[0].push_back(0);
    vb used(n);
    used[0] = true;
    qp que;
    que.push({0, 0});
    while (!que.empty()) {
        ll v = que.front().first;
        ll d = que.front().second;
        que.pop();
        rep(i, graph[v].size()) {
            ll next = graph[v][i];
            if (used[next]) continue;
            used[next] = true;
            dis[d + 1].push_back(next);
            que.push({next, d + 1});
        }
    }

    rep(i, n) used[i] = false;
    vvl max20(n, vl(0));
    rep4(i, 0, n - 1) {
        rep(j, dis[i].size()) {
            ll v = dis[i][j];
            max20[v].push_back(x[v]);
            sort(all(max20[v]), greater<ll>());
            used[v] = true;
            rep(k, graph[v].size()) {
                ll next = graph[v][k];
                if (used[next]) continue;
                max20[next].insert(max20[next].end(), all(max20[v]));
                sort(all(max20[next]), greater<ll>());
                if (max20[next].size() > 20) {
                    vl max20next(20);
                    rep(i, 20) max20next[i] = max20[next][i];
                    max20[next] = max20next;
                }
            }
        }
    }

    vl ans(q);
    rep(i, q) {
        ll v, k;
        cin >> v >> k;
        v--; k--;
        ans[i] = max20[v][k];
    }
    rep(i, q) cout << ans[i] << endl;
}
