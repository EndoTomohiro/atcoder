#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvb = vector<vb>;
using ql = queue<ll>;
using ml = map<ll, ll>;
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
    ll n, m;
    cin >> n >> m;

    vvb graph_ab(n, vb(n, false));
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph_ab[a][b] = true;
        graph_ab[b][a] = true;;
    }

    vvb graph_cd(n, vb(n, false));
    rep(i, m) {
        ll c, d;
        cin >> c >> d;
        c--; d--;
        graph_cd[c][d] = true;
        graph_cd[d][c] = true;
    }

    vl vec(n);
    iota(all(vec), 0);

    do {
        bool ok = true;
        rep(i, n) {
            rep(j, n) {
                if (graph_ab[i][j] != graph_cd[vec[i]][vec[j]]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    } while (next_permutation(all(vec)));

    puts("No");
}
