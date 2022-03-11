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
    vl a(n);
    rep(i, n) cin >> a[i];

    vb ans(n);
    rep4(i, 1, n) {
        ll j = 2 * i;
        ll cnt = 0;
        while (j <= n) {
            if (ans[j - 1]) cnt++;
            j += i;
        }
        if (cnt % 2 != a[i - 1]) ans[i - 1] = true;
    }

    ll m = 0;
    rep(i, n) {
        if (ans[i]) m++;
    }

    cout << m << endl;
    if (m == 0) return 0;
    rep2(i, n) {
        if (ans[i - 1]) cout << i << ' ';
    }
    cout << endl;
}
