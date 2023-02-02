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
using dl = deque<pl>;
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
    ll q;
    cin >> q;
    dl que;
    rep(i, q) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll x, c;
            cin >> x >> c;
            que.push_back(pl(x, c));
        }
        else {
            ll c;
            cin >> c;
            ll ans = 0;
            while (c > 0) {
                ll xf = que.front().first;
                ll cf = que.front().second;
                if (cf <= c) {
                    ans += cf * xf;
                    que.pop_front();
                }
                else {
                    ans += c * xf;
                    que.pop_front();
                    que.push_front(pl(xf, cf-c));
                }
                c -= cf;
            }
            cout << ans << endl;
        }
    }
}
