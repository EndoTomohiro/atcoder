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
using qp = queue<pl>;
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
    ll h, w, ch, cw, dh, dw;
    cin >> h >> w >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;
    vs s(h);
    rep(i, h) cin >> s[i];

    vvl dist(h, vl(w, -1));
    vp vec;
    qp que;
    dist[ch][cw] = 0;
    vec.push_back({ch, cw});
    que.push({ch, cw});

    while (!que.empty()) {
        while (!que.empty()) {
            ll vh = que.front().first;
            ll vw = que.front().second;
            if (vh == dh && vw == dw) {
                cout << dist[dh][dw] << endl;
                return 0;
            }
            que.pop();

            vl dx = {1, 0, -1, 0};
            vl dy = {0, 1, 0, -1};
            rep(i, 4) {
                ll a = vh + dx[i];
                ll b = vw + dy[i];
                if (a == -1 || a == h || b == -1 || b == w) continue;
                if (dist[a][b] != -1) continue;
                if (s[a][b] == '#') continue;
                dist[a][b] = dist[vh][vw];
                vec.push_back({a, b});
                que.push({a, b});
            }
        }

        vp vec2;

        rep(k, vec.size()) {
            ll vh = vec[k].first;
            ll vw = vec[k].second;
            vl dx = {-2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
            vl dy = {-2, -1, 0, 1, 2, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2};
            rep(i, 20) {
                ll a = vh + dx[i];
                ll b = vw + dy[i];
                if (a < 0 || a >= h || b < 0 || b >= w) continue;
                if (dist[a][b] != -1) continue;
                if (s[a][b] == '#') continue;
                dist[a][b] = dist[vh][vw] + 1;
                vec2.push_back({a, b});
                que.push({a, b});
            }
        }

        vec = vec2;
    }

    cout << -1 << endl;

}
