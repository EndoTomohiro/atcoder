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
using ml = map<ll, ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
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
bool comp(pl a, pl b) {
    ll al = a.first;
    ll ar = a.second;
    ll bl = b.first;
    ll br = b.second;

    if (ar != br) return ar < br;
    else return al < bl;
}

int main() {
    ll n, d;
    cin >> n >> d;

    vp wall(n);
    rep(i, n) {
        cin >> wall[i].first >> wall[i].second;
    }
    sort(all(wall), comp);

    ll cnt = 0, ans = 0;
    while (true) {
        ans++;
        ll x = wall[cnt].second;
        while (x + d - 1 >= wall[cnt].first) {
            cnt++;
            if (cnt == n) {
                cout << ans << endl;
                return 0;
            }
        }
    }
}
