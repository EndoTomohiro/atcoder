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

    vl a(n), vec(3, 0);
    rep(i, n) cin >> a[i];

    ll ans = 1;

    rep(i, n) {
        vl vec2;
        rep(j, 3) {
            if (vec[j] == a[i]) vec2.push_back(j);
        }
        if (!vec2.size()) {
            cout << 0 << endl;
            return 0;
        }
        vec[vec2[0]] = a[i] + 1;
        ans *= vec2.size();
        ans %= dif;
    }

    cout << ans << endl;
}
