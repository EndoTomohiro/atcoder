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
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vl h(n);
    rep(i, n) cin >> h[i];

    vvl graph(n, vl(0));
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    rep(i, n) sort(all(graph[i]), greater<ll>());

    vl joy(n, -INF);
    joy[0] = 0;

    ql que;
    rep(i, graph[0].size()) {
        ll next = graph[0][i];
        que.push(next);
        if (h[0] < h[next]) joy[next] = (h[0] - h[next]) * 2;
        else joy[next] = h[0] - h[next];
    }

    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        rep(i, graph[v].size()) {
            ll next = graph[v][i];
            ll joy_next;
            if (h[v] < h[next]) joy_next = joy[v] + (h[v] - h[next]) * 2;
            else joy_next = joy[v] + h[v] - h[next];
            if (chmax(joy[next], joy_next)) que.push(next);
        }
    }

    cout << *max_element(all(joy)) << endl;
}
