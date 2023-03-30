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
    ll a, n, m;
    cin >> a >> n >> m;

    vl v(n), l(n);
    rep(i, n) cin >> v[i] >> l[i];
    vl u(m), r(m);
    rep(i, m) cin >> u[i] >> r[i];

    vl suml(n+1);
    rep(i, n) suml[i+1] = suml[i] + l[i];
    vl sumr(m+1);
    rep(i, m) sumr[i+1] = sumr[i] + r[i];

    vl sumall(n+m+2);
    rep(i, n+1) sumall[i] = suml[i];
    rep(i, m+1) sumall[n+i+1] = sumr[i];
    sort(all(sumall));
    sumall.erase(unique(all(sumall)), sumall.end());

    ll cntl = 0, cntr = 0, ans = 0;
    rep2(i, sumall.size()-1) {
        while (cntl+1 < n && suml[cntl+1] < sumall[i]) cntl++;
        while (cntr+1 < m && sumr[cntr+1] < sumall[i]) cntr++;
        if (v[cntl] == u[cntr]) ans += sumall[i] - sumall[i-1];
    }
    cout << ans << endl;
}
