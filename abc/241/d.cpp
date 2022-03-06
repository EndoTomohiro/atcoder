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
using msl = multiset<ll>;
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
    ll q;
    cin >> q;
    msl st;
    vl ans;
    rep(i, q) {
        ll n;
        cin >> n;
        if (n == 1) {
            ll x;
            cin >> x;
            st.insert(x);
        }
        else if (n == 2) {
            ll x, k;
            cin >> x >> k;
            auto it = st.upper_bound(x);
            bool ok = true;
            rep(j, k) {
                if (it == st.begin()) {
                    ans.push_back(-1);
                    ok = false;
                    break;
                }
                it--;
            }
            if (ok) ans.push_back(*it);
        }
        else {
            ll x, k;
            cin >> x >> k;
            auto it = st.lower_bound(x);
            if (it == st.end()) {
                ans.push_back(-1);
                continue;
            }
            bool ok = true;
            rep(j, k - 1) {
                it++;
                if (it == st.end()) {
                    ans.push_back(-1);
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(*it);
        }
    }

    rep(i, ans.size()) cout << ans[i] << endl;
}
