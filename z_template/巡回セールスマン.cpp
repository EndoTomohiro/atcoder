#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
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

ll V, E;
ll G[20][20];  // グラフ
ll dp[50000][20];
// メモ化再帰
ll rec(ll S, ll v) {  
    if (S == 0) {
        if (v == 0) {
            return 0;
        } else {
            return INF;
        }
    }
    if ((S & (1 << v)) == 0) {  // Sに{v}が含まれていない
        return INF;
    }

    ll ret = dp[S][v];
    if (ret != 0) return ret;

    ret = INF;
    rep(u, V) { chmin(ret, rec(S ^ (1 << v), u) + G[u][v]); }
    return ret;
}

int main() {
    cin >> V >> E;

    // グラフの初期化
    rep(i, 20) {
        rep(j, 20) { G[i][j] = INF; }
    }
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    ll ans = rec((1 << V) - 1, 0);

    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}