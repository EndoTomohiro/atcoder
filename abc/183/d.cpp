#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, w;
    cin >> n >> w;

    vector<ll> s(n), t(n), p(n);
    rep(i, n) cin >> s[i] >> t[i] >> p[i];

    vector<ll> a(200010, 0);

    string ok = "Yes";

    rep(i, n) {
        a[s[i]] += p[i];
        a[t[i]] -= p[i];
    }

    rep(i, 200005) {
        a[i+1] += a[i];
        if (a[i] > w) {
            ok = "No";
            break;
        }
    }

    cout << ok << endl;
}