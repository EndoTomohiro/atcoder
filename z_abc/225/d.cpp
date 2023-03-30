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
    ll n, q;
    cin >> n >> q;

    vl pre(n+1, -1), rea(n+1, -1);
    vvl ans(0, vl(0));

    rep(i, q) {
        ll c;
        cin >> c;

        if (c == 1) {
            ll x, y;
            cin >> x >> y;
            pre[y] = x;
            rea[x] = y;
        }

        else if (c == 2) {
            ll x, y;
            cin >> x >> y;
            pre[y] = -1;
            rea[x] = -1;
        }

        else {
            ll x;
            cin >> x;
            vl ansx;
            while (pre[x] != -1) {
                x = pre[x];
            }
            while (x != -1) {
                ansx.push_back(x);
                x = rea[x];
            }
            ans.push_back(ansx);
        }
    }

    rep(i, ans.size()) {
        cout << ans[i].size();
        rep(j, ans[i].size()) {
            cout << ' ' << ans[i][j];
        }
        cout << endl;
    }
}