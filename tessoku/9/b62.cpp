#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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

// 深さ優先探索
vb seen(100010);
ll n, m;
stack<ll> que, path;
vvl graph(100010);
void dfs(ll v) {
    if (v == n - 1) {
        path = que;
        return;
    }
    seen[v] = true; // v を訪問済みにする

    // v から行ける各頂点 next_v について
    for (auto next_v : graph[v]) {
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        que.push(next_v);
        dfs(next_v); // 再帰的に探索
        que.pop();
    }
    return;
}

int main() {
    cin >> n >> m;
    // グラフ入力受取（ここでは有向グラフを想定）
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    que.push(0);
    dfs(0);
    vl ans;
    while (!path.empty()) {
        ll v = path.top();
        ans.push_back(v);
        path.pop();
    }
    reverse(all(ans));
    rep(i, ans.size()) cout << ans[i] + 1 << ' ';
    cout << endl;
}