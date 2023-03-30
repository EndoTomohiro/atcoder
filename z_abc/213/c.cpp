#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
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
    ll h, w, n;
    cin >> h >> w >> n;

    vt vec(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        vec[i] = {a, b, i+1};
    }

    sort(all(vec));
    ll first = 0;
    ll count = 0;
    rep(i, n) {
        ll first_i = get<0>(vec[i]);
        if (first == first_i) get<0>(vec[i]) = count;
        else {
            count++;
            get<0>(vec[i]) = count;
            first = first_i;
        }
        swap(get<0>(vec[i]), get<1>(vec[i]));
    }

    sort(all(vec));
    ll second = 0;
    count = 0;
    rep(i, n) {
        ll second_i = get<0>(vec[i]);
        if (second == second_i) get<0>(vec[i]) = count;
        else {
            count++;
            get<0>(vec[i]) = count;
            second = second_i;
        }
        swap(get<0>(vec[i]), get<2>(vec[i]));
    }

    sort(all(vec));
    rep(i, n) cout << get<1>(vec[i]) << ' ' << get<2>(vec[i]) << endl;
}