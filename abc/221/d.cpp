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

    vp vec;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, 1));
        vec.push_back(make_pair(a + b, -1));
    }

    sort(all(vec));

    ll cnt = -1;
    ll day = 0;
    vl ans(n);

    rep(i, 2 * n) {
        ll a = vec[i].first;
        ll b = vec[i].second;

        if (cnt >= 0) {
            ans[cnt] += a - day;
        }

        cnt += b;
        day = a;
    }

    rep(i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}