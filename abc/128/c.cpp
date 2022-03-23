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
    vvl graph(m, vl(0));
    rep(i, m) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll s;
            cin >> s;
            graph[i].push_back(s - 1);
        }
    }
    vl p(m);
    rep(i, m) cin >> p[i];

    ll ans = 0;
    rep(i, 1 << n) {
        bitset<15> bit(i);
        vb vec(m);
        bool ok = true;
        rep(j, n) if (bit.test(j)) vec[j] = true;
        rep(j, m) {
            ll cnt = 0;
            rep(k, graph[j].size()) {
                if (vec[graph[j][k]]) cnt++;
            }
            if (cnt % 2 != p[j]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
