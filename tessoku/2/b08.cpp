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
    vvl graph(1510, vl(1510));
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        graph[x][y]++;
    }
    rep2(i, 1500) rep2(j, 1500) {
        graph[i][j] += graph[i][j-1] + graph[i-1][j] - graph[i-1][j-1];
    }
    ll q;
    cin >> q;
    rep(i, q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << graph[c][d] - graph[a-1][d] - graph[c][b-1] + graph[a-1][b-1] << endl;
    }
}
