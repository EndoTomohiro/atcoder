#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
using vps = vector< pair<string, string> >;
const double pi = 3.14159265359;
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

    vps vec(n);
    rep(i, n) cin >> vec[i].first >> vec[i].second;

    sort(all(vec));

    rep(i, n-1) {
        if (vec[i] == vec[i+1]) {
            cout << "Yes" << endl;
            exit(0);
        }
    }

    cout << "No" << endl;
}