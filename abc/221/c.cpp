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

    string sn = to_string(n);
    ll keta = sn.size();

    ll ans = 0;

    rep(i, 1 << keta) {
        bitset<10> bit(i);
        ll c1 = 1, c2 = 1;
        ll s1 = 0, s2 = 0;
        vl vec1, vec2;
        rep(j, keta) {
            if (bit.test(j)) vec1.push_back(sn[j] - '0');
            else vec2.push_back(sn[j] - '0');
        }
        sort(all(vec1));
        sort(all(vec2));

        rep(j, vec1.size()) {
            s1 += vec1[j] * c1;
            c1 *= 10;
        }

        rep(j, vec2.size()) {
            s2 += vec2[j] * c2;
            c2 *= 10;
        }

        chmax(ans, s1 * s2);
    }

    cout << ans << endl;
}