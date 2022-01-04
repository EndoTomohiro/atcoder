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
using qs = queue<string>;
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

    qs que;
    que.push("a");

    vs ans;

    while (!que.empty()) {
        string s = que.front();
        que.pop();

        if (s.size() == n) {
            ans.push_back(s);
            continue;
        }

        int maxs = 0;
        rep(i, s.size()) chmax(maxs, s[i] - 'a');

        rep(j, maxs + 2) que.push(s + char(int('a') + j));
    }

    sort(all(ans));

    rep(i, ans.size()) cout << ans[i] << endl;
}
