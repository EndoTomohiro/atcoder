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

int main() {
    ll n;
    cin >> n;
    vl l(n), vec(1010);
    rep(i, n) {
        cin >> l[i];
        vec[l[i]]++;
    }
    rep(i, 1000) vec[i + 1] += vec[i];

    ll ans = 0;
    rep(i, n - 1) rep3(j, i + 1, n) {
        ll l1 = abs(l[i] - l[j]);
        ll l2 = min(l[i] + l[j], ll(1001));
        ans += vec[l2 - 1] - vec[l1];
        if (l1 < l[i] && l[i] < l2) ans--;
        if (l1 < l[j] && l[j] < l2) ans--;
    }
    ans /= 3;
    cout << ans << endl;
}
