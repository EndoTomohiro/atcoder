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
template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vvl vec(10, vl(0));
    rep(i, n) vec[s[i] - '0'].push_back(i);

    ll ans = 0;

    rep(i, 1000) {
        ll i1 = i / 100;
        ll i2 = (i - i1 * 100) / 10;
        ll i3 = i % 10;

        if (!vec[i1].size() || !vec[i2].size() || !vec[i3].size()) continue;

        ll cnt = vec[i1][0];

        rep(j, vec[i2].size()) {
            if (chmax(cnt, vec[i2][j])) {
                bool tf = false;
                rep(k, vec[i3].size()) {
                    if (chmax(cnt, vec[i3][k])) {
                        ans++;
                        tf = true;
                        break;
                    }
                }
                if (tf) break;
            }
        }
    }
    cout << ans << endl;
}
