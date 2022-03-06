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
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
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
    vl a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i] % n;
    }

    vl used(n + 1, -1), vec(n + 10);
    used[0] = 0;
    ll s, t;
    rep(i, k) {
        vec[i + 1] = vec[i] + a[vec[i] % n];
        if (used[vec[i + 1] % n] != -1) {
            s = used[vec[i + 1] % n];
            t = i + 1;
            break;
        }
        used[vec[i + 1] % n] = i + 1;
    }
    
    ll ans;
    if (k <= s) ans = vec[k];
    else {
        ll p = t - s;
        ll x = vec[t] - vec[s];
        ll a = (k - s - 1) / p;
        ll b = (k - s - 1) % p;
        ans = vec[s + b + 1] + a * x;
    }
    cout << ans << endl;
}
