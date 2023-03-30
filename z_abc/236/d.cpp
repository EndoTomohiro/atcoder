#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair< ll, set<ll> >;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<pl>;
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
    ll n;
    cin >> n;

    vvl graph(2 * n - 1, vl(0));
    rep(i, 2 * n - 1) rep(j, 2 * n - 1 - i) {
        ll a;
        cin >> a;
        graph[i].push_back(a);
    }

    ll ans = 0;
    set<ll> st;
    rep(i, 2 * n) st.insert(i);
    ql que;
    que.push(make_pair(0, st));

    ll cnt = 0;
    while (!que.empty()) {
        ll v = que.front().first;
        set<ll> u = que.front().second;
        que.pop();
        ll p = *u.begin();
        u.erase(p);
        for(auto itr = u.begin(); itr != u.end(); ++itr) {
            set<ll> u2 = u;
            ll q = *itr;
            ll w = graph[p][q - p - 1];
            ll x = v ^ w;
            u2.erase(q);
            if (!u2.size()) chmax(ans, x);
            else que.push(make_pair(x, u2));
        }
    }

    cout << ans << endl;
}
