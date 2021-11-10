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
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

// 各桁の値の合計
ll keta_sum(ll n) {
    ll s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vl vec(100000, -1);
    vec[n] = 0;

    ll cnt = k;
    ll sta = 0;

    for (ll i = 1; i <= k; i++) {
        n = (n + keta_sum(n)) % 100000;
        if (vec[n] == -1) vec[n] = i;
        else {
            sta = vec[n];
            cnt = i - vec[n];
            break;
        }
        if (i == k) {
            cout << n << endl;
            exit(0);
        }
    }

    rep(i, 100000) {
        if (vec[i] >= sta && (k - vec[i]) % cnt == 0) {
            cout << i << endl;
            exit(0);
        }
    }
}