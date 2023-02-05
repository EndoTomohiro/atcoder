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
    ll h, w, n;
    cin >> h >> w >> n;
    vvl x(h+1, vl(w+1)), y(h+2, vl(w+2)), graph(h+1, vl(w+1));
    rep(i, n) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        x[a][b]++;
        y[a][d+1]--;
        y[c+1][b]--;
        y[c+1][d+1]++;
    }
    rep2(i, h) {
        rep2(j, w) {
            graph[i][j] = graph[i][j-1] + graph[i-1][j] - graph[i-1][j-1] + x[i][j] + y[i][j];
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}
