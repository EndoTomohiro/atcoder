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

int main() {
    ll N, C;
    cin >> N >> C;

    vp vec;

    rep(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        vec.push_back(make_pair(a, c));
        vec.push_back(make_pair(b + 1, -c));
    }

    sort(all(vec));

    ll money = 0;
    ll ans = 0;

    rep(i, 2 * N - 1) {
        ll day = vec[i + 1].first - vec[i].first;
        money += vec[i].second;
        ans += min(C, money) * day;
    }

    cout << ans << endl;
}