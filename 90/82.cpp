#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
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

ll mod = 1000000007;

ll calc(ll a, ll b) {
    if (b <= 0) return 1;
    else if (b % 2 == 0) {
        ll d = calc(a, b / 2);
        return (d * d) % mod;
    }
    else return (a * calc(a, b - 1)) % mod;
}

ll f(ll X) {
	// Calculate 1 + 2 + ... + X mod 1000000007
	ll v1 = X % mod;
	ll v2 = (X + 1) % mod;
	ll v = v1 * v2 % mod;
    return v * calc(2, mod - 2) % mod;
}

int main() {
    ll l, r;
    cin >> l >> r;

    vl power10(22);
    power10[0] = 1;
    rep2(i, 19) power10[i] = 10ULL * power10[i-1];

    ll ans = 0;

    rep2(i, 19) {
        ll vl = max(l, power10[i - 1]);
        ll vr = min(r, power10[i] - 1ULL);
        if (vl > vr) continue;
        ll val = (f(vr) - f(vl - 1) + mod) % mod;
        ans += 1ULL * i * val;
        ans %= mod;
    }

    cout << ans << endl;
}