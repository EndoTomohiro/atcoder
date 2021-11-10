#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
const double pi = 3.14159265359;
const ll INF = 1010000000000000;
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
    ll n;
    cin >> n;

    vvl graph(1010, vl(1010));
    rep(i, n) {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        graph[lx][ly]++;
        graph[lx][ry]--;
        graph[rx][ly]--;
        graph[rx][ry]++;
    }

    vvl paper(1010, vl(1010));

    rep(i, 1001) rep2(j, 1, 1001) graph[i][j] += graph[i][j-1];

    rep(j, 1001) rep2(i, 1, 1001) graph[i][j] += graph[i-1][j];


    vl ans(n);
    rep(i, 1001) rep(j, 1001) {
        if (graph[i][j] >= 1) ans[graph[i][j] - 1]++;
    }

    rep(i, n) cout << ans[i] << endl;

}