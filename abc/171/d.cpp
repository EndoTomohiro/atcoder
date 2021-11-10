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
    ll n;
    cin >> n;

    vl vec(100001);
    rep(i, n) {
        ll a;
        cin >> a;
        vec[a]++;
    }

    ll sum = 0;
    rep2(i, 100000) sum += i * vec[i];

    ll q;
    cin >> q;

    vl ans(q);
    rep(i, q) {
        ll b, c;
        cin >> b >> c;
        sum += vec[b] * (c - b);
        vec[c] += vec[b];
        vec[b] = 0;
        ans[i] = sum;
    }

    rep(i, q) cout << ans[i] << endl;
}