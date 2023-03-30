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
using ql = queue<ll>;
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

int main() {
    ll n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--; t--; x--;
    vvl graph(n);
    rep(i, m) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vl vec0(n), vec1(n);
    vec0[s]++;
    rep(e, k) {
        vl vec0e = vec0, vec1e = vec1;
        rep(i, n) {
            if (!vec0e[i]) continue;
            rep(j, graph[i].size()) {
                ll r = graph[i][j];
                if (r != x) {
                    vec0[r] += vec0e[i];
                    vec0[r] %= dif;
                }
                else {
                    vec1[r] += vec0e[i];
                    vec1[r] %= dif;
                }
            }
            vec0[i] -= vec0e[i];
            if (vec0[i] < 0) vec0[i] += dif;
        }
        rep(i, n) {
            if (!vec1e[i]) continue;
            rep(j, graph[i].size()) {
                ll r = graph[i][j];
                if (r != x) {
                    vec1[r] += vec1e[i];
                    vec1[r] %= dif;
                }
                else {
                    vec0[r] += vec1e[i];
                    vec0[r] %= dif;
                }
            }
            vec1[i] -= vec1e[i];
            if (vec1[i] < 0) vec1[i] += dif;
        }
    }
    cout << vec0[t] << endl;
}
