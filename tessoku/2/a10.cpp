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
    ll n;
    cin >> n;
    vl a(n+1);
    rep2(i, n) cin >> a[i];
    vl before(n), after(n);
    rep3(i, 2, n) before[i] = max(before[i-1], a[i-1]);
    rep4(i, 2, n-1) after[i] = max(after[i+1], a[i+1]);
    ll d;
    cin >> d;
    vl ans(d);
    rep(i, d) {
        ll l, r;
        cin >> l >> r;
        ans[i] = max(before[l], after[r]);
    }
    rep(i, d) cout << ans[i] << endl;
}

