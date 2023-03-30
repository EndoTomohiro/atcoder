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

ll sum_while(ll a, ll s) {
    return (2 * a - (s - 1)) * s / 2;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) cin >> a[i];

    sort(all(a), greater<ll>());
    a.push_back(0);

    ll cnt = 0;
    ll ans = 0;

    rep(i, n) {
        ll s = a[i] - a[i+1];
        if (cnt + s * (i + 1) <= k) {
            cnt += s * (i + 1);
            ans += sum_while(a[i], s) * (i + 1);
        }
        else {
            ll t = (k - cnt) / (i + 1);
            ll r = (k - cnt) % (i + 1);
            ans += sum_while(a[i], t) * (i + 1) + (a[i] - t) * r;
            break;
        }
    }

    cout << ans << endl;
}