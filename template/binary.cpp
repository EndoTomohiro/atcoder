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

// x が条件を満たすかどうか
bool p(ll x) {}

// p(x) = true となる最小の x を返す
ll binary_search() {
    ll left, right;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (p(mid)) right = mid;
        else left = mid;
    }
    return right;
}

// p(x) = true となる最大の x を返す
ll not_binary_search() {
    ll left, right;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (!p(mid)) right = mid;
        else left = mid;
    }
    return left;
}

int main() {}