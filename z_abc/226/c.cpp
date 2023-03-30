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
    ll n;
    cin >> n;

    vl t(n), k(n);
    vvl a;

    rep(i, n) {
        cin >> t[i] >> k[i];
        vl vec(k[i]);
        rep(j, k[i]) {
            cin >> vec[k[i] - 1 - j];
            vec[k[i] - 1 - j]--;
        }
        a.push_back(vec);
    }

    ll ans = t[n - 1];
    vb tf(n, false);

    priority_queue< ll, vl, greater<ll> > que;
    rep(i, k[n-1]) {
        ll x = a[n-1][i];
        que.push(x);
        tf[x] = true;
        ans += t[x];
    }

    while (!que.empty()) {
        ll v = que.top();
        que.pop();
        rep(i, k[v]) {
            ll x = a[v][i];
            if (!tf[x]) {
                que.push(x);
                tf[x] = true;
                ans += t[x];
            }
        }
    }

    cout << ans << endl;
}