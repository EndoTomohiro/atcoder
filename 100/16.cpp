#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
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

ll jisho(vl r, vl vec, ll ansr) {
    if (r.size() == 1) return ansr;

    ll lower = 0;
    rep(i, vec.size()) {
        if (vec[i] < r[0]) lower++;
    }

    rep(i, r.size() - 1) {
        lower *= (i + 1);
    }

    ansr += lower;

    rep(i, vec.size()) {
        if (vec[i] == r[0]) {
            vec.erase(vec.begin() + i);
            break;
        }
    }

    r.erase(r.begin());

    return jisho(r, vec, ansr);
}

int main() {
    ll n;
    cin >> n;

    vl p(n), q(n), vec(n);
    rep(i, n) {
        cin >> p[i];
        vec[i] = i + 1;
    }
    rep(i, n) {
        cin >> q[i];
    }

    cout << abs(jisho(q, vec, 1) - jisho(p, vec, 1)) << endl;
}