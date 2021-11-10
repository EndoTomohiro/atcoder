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

const int MAX_N = 2000;

vvl g;
bool temp[MAX_N];
void dfs(ll v) {
    if (temp[v]) return;
    temp[v] = true;
    for (auto vv: g[v]) dfs(vv);
}

int main() {
    ll n, m;
    cin >> n >> m;
    g.resize(n);

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }

    int ans = 0;
    rep(i, n) {
        rep(j, n) temp[j] = false;
        dfs(i);
        rep(j, n) {
            if (temp[j]) ans++;
        }
    }

    cout << ans << endl;
}