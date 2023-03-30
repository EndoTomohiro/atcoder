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
    string s;
    cin >> s;

    vl r(n), g(n), b(n);
    rep(i, n) {
        if (i) {
            r[i] = r[i - 1];
            g[i] = g[i - 1];
            b[i] = b[i - 1];
        }
        if (s[i] == 'R') r[i]++;
        else if (s[i] == 'G') g[i]++;
        else b[i]++;
    }

    ll ans = 0;
    rep(i, n - 2) rep3(j, i + 1, n - 1) {
        if (s[i] == 'R' && s[j] == 'G') {
            ans += b[n - 1] - b[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'B') ans--;
        }
        else if (s[i] == 'R' && s[j] == 'B') {
            ans += g[n - 1] - g[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'G') ans--;
        }
        else if (s[i] == 'G' && s[j] == 'R') {
            ans += b[n - 1] - b[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'B') ans--;
        }
        else if (s[i] == 'G' && s[j] == 'B') {
            ans += r[n - 1] - r[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'R') ans--;
        }
        else if (s[i] == 'B' && s[j] == 'R') {
            ans += g[n - 1] - g[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'G') ans--;
        }
        else if (s[i] == 'B' && s[j] == 'G') {
            ans += r[n - 1] - r[j];
            ll k = 2 * j - i;
            if (k < n && s[k] == 'R') ans--;
        }

    }

    cout << ans << endl;
}
