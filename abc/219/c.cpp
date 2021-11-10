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

string x;
int num(char c) {
    rep(i, 26) {
        if (x[i] == c) return i;
    }
    return 0;
}

bool comp(string ls, string rs) {
    rep(i, min(ls.size(), rs.size())) {
        if (num(ls[i]) != num(rs[i])) return num(ls[i]) < num(rs[i]);
    }
    return ls.size() < rs.size();
}

int main() {
    ll n;
    cin >> x >> n;

    vs vec(n);
    rep(i, n) cin >> vec[i];

    sort(all(vec), comp);

    rep(i, n) cout << vec[i] << endl;
}