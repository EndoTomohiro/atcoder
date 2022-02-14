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
using dl = deque<ll>;
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
    ll n;
    cin >> n;
    vl a(n);
    vvl graph_x(n, vl(0)), graph_y(n, vl(0));
    rep(i, n) {
        cin >> a[i];
        rep(j, a[i]) {
            ll x, y;
            cin >> x >> y;
            x--;
            graph_x[i].push_back(x);
            graph_y[i].push_back(y);
        }
    }

    ll ans = 0;
    rep(r, 1 << n) {
        bitset<20> bit(r);
        ll sum = 0;
        rep(h, n) if (bit.test(h)) sum++;
        bool ok = true;
        rep(i, n) {
            if (!bit.test(i)) continue;
            rep(j, a[i]) {
                if (bit.test(graph_x[i][j]) && !graph_y[i][j] || !bit.test(graph_x[i][j]) && graph_y[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) chmax(ans, sum);
    }
    cout << ans << endl;
}
