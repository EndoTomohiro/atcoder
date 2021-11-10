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
const double pi = 3.14159265359;
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

int main() {
    int n;
    cin >> n;

    vvl a(n, vl(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    int m;
    cin >> m;

    vvl bad(n, vl(0));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        bad[x].push_back(y);
        bad[y].push_back(x);
    }

    vl num;
    rep(i, n) num.push_back(i);

    ll ans = INF;
    do {
        ll sum = 0;
        rep(i, n) {
            if (i && count(all(bad[num[i-1]]), num[i]) != 0) {
                sum = INF;
                break;
            }
            sum += a[num[i]][i];
        }
        chmin(ans, sum);
    } while (next_permutation(all(num)));

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}