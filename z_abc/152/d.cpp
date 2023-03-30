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

vl vec(10);

ll f(ll i, ll keta, ll top, ll bottom){
    if (keta == 1) return 0;
    if (keta == 2) {
        if (top < bottom) return 0;
        else {
            vec[0]++;
            return 0;
        }
    }
    if (top < bottom) {
        ll keta_j = 2;
        while (keta_j < keta) {
            vec[keta_j - 2]++;
            keta_j++;
        }
        return 0;
    }
    if (top > bottom) {
        ll keta_j = 2;
        while (keta_j <= keta) {
            vec[keta_j - 2]++;
            keta_j++;
        }
        return 0;
    }
    ll center = stoll(to_string(i).substr(1, keta - 2));
    ll keta_j = 2;
    vec[0]++;
    while (keta_j < keta) {
        vec[keta_j - 2]++;
        keta_j++;
    }
    return center;
}

ll same_num(ll i, ll n) {
    ll cnt = 0;
    ll x = i;
    while (x <= n) {
        cnt++;
        x = x * 10 + i;
    }
    return cnt;
}

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    ll same = 0;
    rep2(i, n) {
        if (i % 10 == 0) continue;
        string si = to_string(i);
        ll keta = si.size();
        ll top = si[0] - '0';
        ll bottom = si[keta - 1] - '0';
        if (top == bottom) same++;
        ans += f(i, keta, top, bottom);
    }
    rep(i, 10) ans += pow(10, i) * vec[i];

    ans *= 2;
    ans += same;
    cout << ans << endl;
}
