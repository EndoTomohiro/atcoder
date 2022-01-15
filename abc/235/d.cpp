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
using qp = queue<pl>;
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
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll a, n;
    cin >> a >> n;

    ql que;
    que.push(1);

    vl vec(1000010, INF);
    vec[1] = 0;

    while (!que.empty()) {
        ll x = que.front();
        que.pop();

        ll y = x * a;
        if (y < 1000000) {
            if (chmin(vec[y], vec[x] + 1)) {
                que.push(y);
            }
        }
        
        if (x >= 10 && x % 10) {
            string str_x = to_string(x);
            ll siz_x = str_x.size();
            ll z = stoll(str_x[siz_x - 1] + str_x.substr(0, siz_x - 1));
            if (chmin(vec[z], vec[x] + 1)) {
                que.push(z);
            }
        }
    }

    if (vec[n] < INF) cout << vec[n] << endl;
    else cout << -1 << endl;
}
