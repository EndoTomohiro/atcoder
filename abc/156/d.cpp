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
using sl = set<ll>;
using dl = deque<ll>;
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

// 累乗
ll myPow(ll x, ll n){
  if (n == 0) return 1;
  else if (n % 2 == 0) return myPow(x * x % dif, n / 2);
  else return x * myPow(x, n - 1) % dif;
}

ll nCr(ll n, ll r) {
    ll x = 1;
    rep(i, r) x = x * (n - i) % dif;
    ll y = 1;
    rep2(i, r) y = y * i % dif;
    ll ans = x * myPow(y, dif - 2) % dif;
    return ans;
}


int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = myPow(2, n) + dif - 1;
    ans += dif - nCr(n, a);
    ans += dif - nCr(n, b);
    ans %= dif;
    cout << ans << endl;
}
