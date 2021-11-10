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

ll binary_search(ll key, ll d, vl vec) {
    ll left = 0, right = vec.size() - 1, dd = LONG_MAX;

    while (right >= left) {
        ll mid = left + (right - left) / 2;
        if (vec[mid] == key) return 0;
        else {
            chmin(dd, abs(key - vec[mid]));
            if (vec[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
    }

    if (key > vec[vec.size() - 1]) chmin(dd, d - key);

    return dd;
}

int main() {
    ll d, n, m;
    cin >> d >> n >> m;

    vl branch(n);
    branch[0] = 0;
    rep2(i, 1, n) cin >> branch[i];
    sort(branch.begin(), branch.end());

    vl deri(m);
    rep(i, m) cin >> deri[i];

    ll ans = 0;

    rep(i, m) {
        ans += binary_search(deri[i], d, branch);
    }

    cout << ans << endl;
}