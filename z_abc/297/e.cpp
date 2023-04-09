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
using dl = deque<ll>;
using pri = priority_queue< ll, vl, greater<ll> >;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    pri que;
    rep(i, n) cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    ml mp;
    rep(i, a.size()) {
        mp[a[i]]++;
        que.push(a[i]);
    }
    ll cnt = 0;
    while (true) {
        ll v = que.top();
        que.pop();
        cnt++;
        if (cnt == k) {
            cout << v << endl;
            return 0;
        }
        rep(i, n) {
            if (!mp[v + a[i]]) {
                que.push(v + a[i]);
                mp[v + a[i]]++;
            }
        }
    }
}
