#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vt = vector<tl>;
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
    ll n;
    cin >> n;

    vt vec(n);
    ll aoki = 0, taka = 0;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        aoki += a;
        vec[i] = make_tuple(2 * a + b, a, b);
    }

    sort(all(vec), greater< tuple<ll, ll, ll> >());

    rep(i, n) {
        aoki -= get<1>(vec[i]);
        taka += get<1>(vec[i]) + get<2>(vec[i]);
        if (taka > aoki) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}