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

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    vl vec;
    vec.push_back(0);

    vl used(n, -1);
    used[0] = 0;

    rep(i, k) {
        ll next = a[vec[i]];
        if (used[next] != -1) {
            cout << vec[used[next] + (k - used[next]) % (i + 1 - used[next])] + 1 << endl;
            return 0;
        }
        used[next] = i + 1;
        vec.push_back(next);
    }

    cout << vec[k] + 1 << endl;
}
