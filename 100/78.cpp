#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vvt = vector<vt>;
using vs = vector<string>;
#define pi 3.14159265359;
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

int main() {
    ll m, n, k;
    cin >> m >> n >> k;

    vvt acc(m+1, vt(n+1));
    rep(i, m) {
        string joi;
        cin >> joi;
        rep(j, n) {
            acc[i+1][j+1] = make_tuple(get<0>(acc[i+1][j]) + get<0>(acc[i][j+1]) - get<0>(acc[i][j]),
                                    get<1>(acc[i+1][j]) + get<1>(acc[i][j+1]) - get<1>(acc[i][j]),
                                    get<2>(acc[i+1][j]) + get<2>(acc[i][j+1]) - get<2>(acc[i][j]));
            if (joi[j] == 'J') acc[i+1][j+1] = make_tuple(get<0>(acc[i+1][j+1]) + 1, get<1>(acc[i+1][j+1]), get<2>(acc[i+1][j+1]));
            else if (joi[j] == 'O') acc[i+1][j+1] = make_tuple(get<0>(acc[i+1][j+1]), get<1>(acc[i+1][j+1]) + 1, get<2>(acc[i+1][j+1]));
            else acc[i+1][j+1] = make_tuple(get<0>(acc[i+1][j+1]), get<1>(acc[i+1][j+1]), get<2>(acc[i+1][j+1]) + 1);
        }
    }

    vt ans(k);
    rep(i, k) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ans[i] = make_tuple(get<0>(acc[c][d]) - get<0>(acc[a-1][d]) - get<0>(acc[c][b-1]) + get<0>(acc[a-1][b-1]),
                            get<1>(acc[c][d]) - get<1>(acc[a-1][d]) - get<1>(acc[c][b-1]) + get<1>(acc[a-1][b-1]),
                            get<2>(acc[c][d]) - get<2>(acc[a-1][d]) - get<2>(acc[c][b-1]) + get<2>(acc[a-1][b-1]));
    }

    rep(i, k) cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << endl;
}