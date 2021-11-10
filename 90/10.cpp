#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
#define pi 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
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

    vl c1, c2, p1(1, 0), p2(1, 0);
    ll len1 = 0, len2 = 0;
    rep(i, n) {
        ll c, p;
        cin >> c >> p;
        if (c == 1) {
            c1.push_back(i);
            p1.push_back(p);
            len1++;
            if (len1 > 1) p1[len1] += p1[len1-1];
        }
        else {
            c2.push_back(i);
            p2.push_back(p);
            len2++;
            if (len2 > 1) p2[len2] += p2[len2-1];
        }
    }

    ll q;
    cin >> q;

    vl l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    rep(i, q) {
        ll less1 = lower_bound(all(c1), l[i]) - c1.begin();
        ll less2 = lower_bound(all(c2), l[i]) - c2.begin();
        ll less_equal1 = upper_bound(all(c1), r[i]) - c1.begin();
        ll less_equal2 = upper_bound(all(c2), r[i]) - c2.begin();

        cout << p1[less_equal1] - p1[less1] << ' ' << p2[less_equal2] - p2[less2] << endl;
    }
}