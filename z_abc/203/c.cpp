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
    ll n, k;
    cin >> n >> k;
    vp ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;

    sort(all(ab));

    ll ans = 0;
    ll fri = 0;
    ll money = k;

    while (fri < n) {
        ll vil = ab[fri].first;
        if (money - (vil - ans) < 0) {
            cout << ans + money << endl;
            exit(0);
        }
        money -= vil - ans;
        ans = vil;
        while (fri < n && ab[fri].first == vil) {
            money += ab[fri].second;
            fri++;
        }
    }

    cout << ans + money << endl;
}