#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
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

int main() {
    ll h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];

    vvl vec(h, vl(w)), sum01(h, vl(w)), sum10(h, vl(w)), sum11(h, vl(w));
    vec[0][0] = 1; sum01[0][0] = 1; sum10[0][0] = 1; sum11[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') continue;
        if (j > 0) vec[i][j] += sum01[i][j - 1];
        if (i > 0) vec[i][j] += sum10[i - 1][j];
        if (j > 0 && i > 0) vec[i][j] += sum11[i - 1][j - 1];
        vec[i][j] %= dif;
        sum01[i][j] = vec[i][j];
        sum10[i][j] = vec[i][j];
        sum11[i][j] = vec[i][j];
        if (j > 0) {
            sum01[i][j] += sum01[i][j - 1];
            sum01[i][j] %= dif;
        }
        if (i > 0) {
            sum10[i][j] += sum10[i - 1][j];
            sum10[i][j] %= dif;
        }
        if (j > 0 && i > 0) {
            sum11[i][j] += sum11[i - 1][j - 1];
            sum11[i][j] %= dif;
        }
    }
    cout << vec[h - 1][w - 1] << endl;
}
