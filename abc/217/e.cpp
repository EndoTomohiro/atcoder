#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
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

    queue<ll> que1;
    priority_queue< ll, vl, greater<ll> > que2;
    vl ans;

    rep(i, q) {
        ll c;
        cin >> c;

        if (c == 1) {
            ll x;
            cin >> x;
            que1.push(x);
        }

        else if (c == 2) {
            if (que2.empty()) {
                ans.push_back(que1.front());
                que1.pop();
            }
            else {
                ans.push_back(que2.top());
                que2.pop();     
            }
        }

        else {
            while (!que1.empty()) {
                que2.push(que1.front());
                que1.pop();
            }
        }
    }

    rep(i, ans.size()) cout << ans[i] << endl;
}