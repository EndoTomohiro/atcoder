#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvb = vector<vb>;
using ql = queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
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

ll h, w;

ll hanjo(vvb vec, ll c, ll i, ll j) {
    if (c == 0) return 1;
    if (i == h - 1 && j == w - 1) return 0;
    if (vec[i][j]) {
        if (j < w - 1) return hanjo(vec, c, i, j + 1);
        else return hanjo(vec, c, i + 1, 0);
    }
    vvb vec1 = vec, vec2 = vec;
    if (i < h - 1 && j < w - 1) {
        vec1[i][j] = true;
        vec1[i][j + 1] = true;
        vec2[i][j] = true;
        vec2[i + 1][j] = true;
        if (vec[i][j + 1]) return hanjo(vec, c, i, j + 1) + hanjo(vec2, c - 1, i, j + 1);
        return hanjo(vec, c, i, j + 1) + hanjo(vec1, c - 1, i, j + 1) + hanjo(vec2, c - 1, i, j + 1);
    }
    else if (j < w - 1) {
        if (vec[i][j + 1]) return hanjo(vec, c, i, j + 1);
        vec1[i][j] = true;
        vec1[i][j + 1] = true;
        return hanjo(vec, c, i, j + 1) + hanjo(vec1, c - 1, i, j + 1);
    }
    else {
        vec2[i][j] = true;
        vec2[i + 1][j] = true;
        return hanjo(vec, c, i + 1, 0) + hanjo(vec2, c - 1, i + 1, 0);
    }
}

int main() {
    ll a, b;
    cin >> h >> w >> a >> b;
    vvb vec(h, vb(w));
    cout << hanjo(vec, a, 0, 0) << endl;
}
