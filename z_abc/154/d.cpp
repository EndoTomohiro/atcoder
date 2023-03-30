#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vd = vector<double>;
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
    ll n, k;
    cin >> n >> k;
    vl p(n);
    vd vec(n);
    rep(i, n) {
        cin >> p[i];
        rep2(j, p[i]) vec[i] += j;
        vec[i] /= p[i];
    }

    vd s(n - k + 1);
    rep(i, k) s[0] += vec[i];
    rep2(i, n - k) s[i] = s[i - 1] + vec[k + i - 1] - vec[i - 1];
    double ans = double(*max_element(all(s)));
    cout << fixed << setprecision(11);
    cout << ans << endl;
}
