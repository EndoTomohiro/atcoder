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
using pri = priority_queue< ll, vl, greater<ll> >;
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

bool comp(pl p, pl q) {
    return p.second > q.second;
}

int main() {
    ll n, m;
    cin >> n >> m;
    pri que;
    ll ans = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        que.push(a);
        ans += a;
    }
    vp vec(m);
    rep(i, m) cin >> vec[i].first >> vec[i].second;
    sort(all(vec), comp);

    rep(i, m) {
        ll b = vec[i].first;
        ll c = vec[i].second;
        rep(j, b) {
            ll v = que.top();
            if (v >= c) break;
            que.pop();
            que.push(c);
            ans += c - v;
        }
    }
    cout << ans << endl;
}
