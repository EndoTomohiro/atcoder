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
    ll h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];

    vvl yoko(h, vl(0));
    rep(i, h) {
        yoko[i].push_back(-1);
        yoko[i].push_back(w);
    }
    vvl tate(w, vl(0));
    rep(i, w) {
        tate[i].push_back(-1);
        tate[i].push_back(h);
    }

    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') {
            yoko[i].push_back(j);
            tate[j].push_back(i);
        }
    }

    rep(i, h) sort(all(yoko[i]));
    rep(i, w) sort(all(tate[i]));

    vvl graph(h, vl(w, -1));
    rep(i, h) {
        ll l = 0, r = 1;
        rep(j, w) {
            if (s[i][j] == '#') {
                l++; r++;
            }
            else graph[i][j] += yoko[i][r] - yoko[i][l] - 1;
        }
    }
    ll ans = 0;
    rep(j, w) {
        ll l = 0, r = 1;
        rep(i, h) {
            if (s[i][j] == '#') {
                l++; r++;
            }
            else {
                graph[i][j] += tate[j][r] - tate[j][l] - 1;
                chmax(ans, graph[i][j]);
            }
        }
    }
    cout << ans << endl;
}
