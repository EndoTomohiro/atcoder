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

ll n, l, k;
vl a(100010);

bool solve(ll m) {
    ll cnt = 0, pre = 0;
    rep(i, n) {
        if (a[i] - pre >= m && l - a[i] >= m) {
            cnt++;
            pre = a[i];
        }
    }
    if (cnt >= k) return true;
    else return false;
}

int main() {
    cin >> n >> l >> k;
    rep(i, n) cin >> a[i];

    ll left = -1, right = l+1;

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (solve(mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}