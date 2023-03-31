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

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll n = s.size();
    vl cnt(n + 1);
    rep(i, n) {
        if (s[i] == '.') cnt[i + 1] = cnt[i] + 1;
        else cnt[i + 1] = cnt[i];
    }

    ll ans = 0;
    ll left = 0, right = 1;
    while (true) {
        ll num = cnt[right] - cnt[left];
        if (num <= k) {
            chmax(ans, right - left);
            if (right == s.size()) break;
            right++;
        }
        else left++;
    }

    cout << ans << endl;
}