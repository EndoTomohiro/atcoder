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
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

vp rotate(vp tpair) {
    vp pair;
    rep(i, tpair.size()) {
        ll x = tpair[i].first;
        ll y = tpair[i].second;
        if (x >= 0 && y >= 0) pair.push_back(make_pair(-y, x));
        else if (x <= 0 && y >= 0) pair.push_back(make_pair(-y, x));
        else if (x <= 0 && y <= 0) pair.push_back(make_pair(-y, x));
        else pair.push_back(make_pair(-y, x));
    }
    sort(all(pair));
    return pair;
}

bool same(vp spair, vp tpair) {
    pl a = make_pair(spair[0].first - tpair[0].first, spair[0].second - tpair[0].second);
    rep(i, spair.size()) {
        pl b = make_pair(spair[i].first - tpair[i].first, spair[i].second - tpair[i].second);
        if (a != b) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vs s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    vp spair, tpair;

    rep(i, n) rep(j, n) if (s[i][j] == '#') spair.push_back(make_pair(i, j));
    rep(i, n) rep(j, n) if (t[i][j] == '#') tpair.push_back(make_pair(i, j));

    if (spair.size() != tpair.size()) {
        cout << "No" << endl;
        exit(0);
    }

    sort(all(spair));

    if (same(spair, tpair)) {
        cout << "Yes" << endl;
        exit(0);
    }

    tpair = rotate(tpair);

    if (same(spair, tpair)) {
        cout << "Yes" << endl;
        exit(0);
    }

    tpair = rotate(tpair);

    if (same(spair, tpair)) {
        cout << "Yes" << endl;
        exit(0);
    }

    tpair = rotate(tpair);

    if (same(spair, tpair)) {
        cout << "Yes" << endl;
        exit(0);
    }

    cout << "No" << endl;

}