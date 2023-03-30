#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, string>;
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
    ll n, m;
    cin >> n >> m;
    vp vec(m);
    rep(i, m) {
        ll p;
        string s;
        cin >> p >> s;
        vec[i] = make_pair(p, s);
    }

    vb ac(n + 1, false);
    vl wa(n + 1);
    ll cor = 0, pen = 0;
    rep(i, m) {
        ll p = vec[i].first;
        string s = vec[i].second;
        if (!ac[p] && s == "AC") {
            ac[p] = true;
            cor++;
            pen += wa[p];
        }
        else if (!ac[p] && s == "WA") wa[p]++;
    }
    cout << cor << ' ' << pen << endl;
}
