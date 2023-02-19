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
vvl graph(100010);
vl ans(100010);
ll dfs(ll v) {
    seen[v] = true; // v を訪問済みにする

    // v から行ける各頂点 next_v について
    for (auto next_v : graph[v]) {
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        chmax(ans[v], dfs(next_v) + 1); // 再帰的に探索
    }

    return ans[v];
}

int main() {
    ll n, t;
    cin >> n >> t;
    t--;
    // グラフ入力受取（ここでは有向グラフを想定）
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(t);
    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
}