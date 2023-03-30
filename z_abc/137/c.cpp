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
using vvc = vector<vc>;
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
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
    vs s(n);
    vvc c(n, vc(10));
    rep(i, n) {
        cin >> s[i];
        rep(j, 10) c[i][j] = s[i][j];
    }
    rep(i, n) sort(all(c[i]));
    rep(i, n) rep(j, 10) s[i][j] = c[i][j];
    sort(all(s));

    ll ans = 0;
    ll cnt = 1;
    rep2(i, n - 1) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
}
