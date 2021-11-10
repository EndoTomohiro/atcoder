#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
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

int main() {
    ll n, q;
    string s, mae, ato;
    cin >> n >> s >> q;
    mae = s.substr(0, n);
    ato = s.substr(n);
    bool tf = false;

    rep(i, q) {
        ll t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) {
            if (b < n) swap(mae[a], mae[b]);
            else if (n <= a) swap(ato[a-n], ato[b-n]);
            else swap(mae[a], ato[b-n]);
        }
        else {
            swap(mae, ato);
        }
    }

    cout << mae + ato << endl;
}