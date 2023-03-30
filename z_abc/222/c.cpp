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

ll janken(char sj, char tj) {
    if (sj == tj) return 0;
    else if ((sj == 'G' && tj == 'C') || (sj == 'C' && tj == 'P') || (sj == 'P' && tj == 'G')) {
        return 1;
    }
    else return -1;
}

ll comp(pl sp, pl tp) {
    ll sf = sp.first;
    ll ss = sp.second;
    ll tf = tp.first;
    ll ts = tp.second;

    if (sf != tf) return sf > tf;
    else return ss < ts;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vs a(2*n);
    rep(i, 2*n) cin >> a[i];

    vp num;
    rep(i, 2*n) num.push_back(make_pair(0, i));

    rep(i, m) {
        rep(k, n) {
            ll s = num[2 * k].second;
            ll t = num[2 * k + 1].second;
            if (janken(a[s][i], a[t][i]) == 1) num[2 * k].first++;
            if (janken(a[s][i], a[t][i]) == -1) num[2 * k + 1].first++;
        }
        sort(all(num), comp);
    }

    rep(i, 2*n) cout << num[i].second + 1 << endl;
}