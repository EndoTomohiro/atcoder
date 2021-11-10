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

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p=-1) {
    for (int u : to[v]) {
        if (u == p) continue;
        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    ans.resize(n);

    rep(i, q) {
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }

    dfs(0);

    rep(i, n) cout << ans[i] << endl;

    return 0;
}