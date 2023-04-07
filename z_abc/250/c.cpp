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
    ll n, q;
    cin >> n >> q;
    vl vec(n);
    iota(all(vec), 0);
    ml mp;
    rep(i, n) mp[i] = i;

    rep(i, q) {
        ll x;
        cin >> x;
        x--;
        ll a = mp[x];
        ll b;
        if (a != n - 1) b = a + 1;
        else b = a - 1;
        ll y = vec[b];
        vec[a] = y;
        vec[b] = x;
        mp[x] = b;
        mp[y] = a;
    }
    rep(i, n) cout << vec[i] + 1 << ' ';
    cout << endl;
}
