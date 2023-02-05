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
    vvl x(1510, vl(1510)), graph(1510, vl(1510));
    rep(i, n) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        x[a][b]++;
        x[a][d]--;
        x[c][b]--;
        x[c][d]++;
    }
    ll ans = 0;
    rep2(i, 1501) rep2(j, 1501) {
        graph[i][j] = graph[i][j-1] + graph[i-1][j] - graph[i-1][j-1] + x[i][j];
        if (graph[i][j]) ans++;
    }
    cout << ans << endl;
}
