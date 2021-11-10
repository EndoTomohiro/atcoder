#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vt = vector< tuple<ll, ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vvt = vector<vt>;
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

const long long x = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl road(n-1, 1);
    rep(i, n-1) {
        vl amari(30);
        amari[0] = a[i];
        rep(j, 29) amari[j+1] = amari[j] * amari[j] % x;

        bitset<30> s(a[i+1]);
        rep(k, 30) {
            if (s.test(k)) {
                road[i] = road[i] * amari[k] % x;
            }
        }
    }

    vl acc(n);
    rep(i, n-1) acc[i+1] = (acc[i] + road[i]) % x;

    ll ans = 0;
    vl move(0);
    move.push_back(0);
    rep(i, q) {
        ll town;
        cin >> town;
        town--;
        move.push_back(town);
    }
    move.push_back(0);

    rep(i, q+1) {
        ans += abs(acc[move[i+1]] - acc[move[i]]);
        ans %= x;
    }

    cout << ans << endl;
}
