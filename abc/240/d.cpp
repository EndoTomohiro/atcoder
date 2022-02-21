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
using dp = deque<pl>;
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

    dp deq;
    ll ans = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        ans++;
        if (deq.empty()) {
            deq.push_back({a, 1});
            cout << ans << endl;
            continue;
        }
        ll x = deq.back().first;
        ll c = deq.back().second;
        if (x != a) {
            deq.push_back({a, 1});
            cout << ans << endl;
            continue;
        }
        deq.pop_back();
        c++;
        if (c == x) ans -= x;
        else deq.push_back({x, c});
        cout << ans << endl;
    }
}
