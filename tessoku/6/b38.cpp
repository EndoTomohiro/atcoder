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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl left(n), right(n);
    left[0] = 1, right[n-1] = 1;
    rep(i, n-1) {
        if (s[i] == 'A') left[i+1] = left[i] + 1;
        else left[i+1] = 1;
    }
    rep(i, n-1) {
        if (s[n-2-i] == 'A') right[n-2-i] = 1;
        else right[n-2-i] = right[n-1-i] + 1;
    }
    vl ans(n);
    rep(i, n) ans[i] = max(left[i], right[i]);
    cout << accumulate(all(ans), ll(0)) << endl;
}
