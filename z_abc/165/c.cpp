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
using qv = queue<vl>;
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
    ll n, m, q;
    cin >> n >> m >> q;

    vl a(q), b(q), c(q), d(q);
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    qv que;
    vl vec1(1);
    rep(i, m) {
        vec1[0] = i;
        que.push(vec1);
    }

    ll ans = 0;
    while (true) {
        vl vec = que.front();
        ll siz = vec.size();
        if (siz > n) {
            cout << ans << endl;
            return 0;
        }
        que.pop();

        if (siz == n) {
            ll h = 0;
            rep(i, q) {
                if (vec[b[i]] - vec[a[i]] == c[i]) h += d[i];
            }
            chmax(ans, h);
        }

        rep3(i, vec[siz - 1], m) {
            vl vec2 = vec;
            vec2.push_back(i);
            que.push(vec2);
        }
    }
}
