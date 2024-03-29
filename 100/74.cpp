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

const ll dif = 1000000007;

ll calc(ll a, ll b) {
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        ll d = calc(a, b / 2);
        return (d * d) % dif;
    }
    else return (a * calc(a, b - 1)) % dif;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    rep(i, n) {
        ans = ans * (i + 1) % dif;
    }

    rep(i, r) ans = ans * calc(i + 1, dif - 2) % dif;
    rep(i, n - r) ans = ans * calc(i + 1, dif - 2) % dif;

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << nCr(n + k - 1, k) << endl;
}