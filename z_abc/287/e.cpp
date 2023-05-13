#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<string, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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
    vl ans(n);
    vp vec(n);
    rep(i, n) {
        cin >> vec[i].first;
        vec[i].second = i;
    }
    sort(all(vec));
    rep(i, n-1) {
        ll m = min(vec[i].first.size(), vec[i+1].first.size());
        ll cnt = 0;
        rep(j, m) {
            if (vec[i].first[j] == vec[i+1].first[j]) cnt++;
            else break;
        }
        chmax(ans[vec[i].second], cnt);
        chmax(ans[vec[i+1].second], cnt);
    }
    rep(i, n) cout << ans[i] << endl;
}
