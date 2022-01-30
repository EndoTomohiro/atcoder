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
    ll n;
    cin >> n;

    vl a(n), vec(n);
    ml mp;
    rep(i, n) {
        cin >> a[i];
        vec[i] = a[i];
        mp[a[i]]++;
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    ll ans = 0;
    rep(i, vec.size()) {
        ans += mp[vec[i]] * (mp[vec[i]] - 1) / 2;
    }
    rep(k, n) {
        ll ans_k = ans;
        if (mp[a[k]]) ans_k -= mp[a[k]] - 1;
        cout << ans_k << endl;
    }
}
