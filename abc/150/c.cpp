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

bool same_vec(vl a, vl vec) {
    rep(i, a.size()) {
        if (a[i] != vec[i]) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vl p(n), q(n), vec(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    rep(i, n) vec[i] = i + 1;

    ll a, b;
    ll cnt = 1;
    // 順列全探索
    do {
        if (same_vec(p, vec)) a = cnt;
        if (same_vec(q, vec)) b = cnt;
        cnt++;
    } while (next_permutation(all(vec)));

    cout << abs(a - b) << endl;
}
