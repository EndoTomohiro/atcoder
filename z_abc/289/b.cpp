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
    ll n, m;
    cin >> n >> m;
    vvl vec(0);
    ll x = 1, cnt = -1;
    if (m == 0) {
        rep2(i, n) cout << i << ' ';
        cout << endl;
        return 0;
    }
    rep(i, m) {
        ll a;
        cin >> a;
        while (x <= a) {
            vec.push_back({x});
            x++;
            cnt++;
        }
        vec[cnt].push_back(x);
        x++;
    }
    while (x <= n) {
        vec.push_back({x});
        x++;
    }
    rep(i, vec.size()) rep4(j, 0, vec[i].size()-1) cout << vec[i][j] << ' ';
    cout << endl;
}