#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using tu = tuple<ll, ll, char>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using vtu = vector<tu>;
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
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
    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    string s;
    cin >> s;

    vtu vec(n);
    rep(i, n) vec[i] = make_tuple(y[i], x[i], s[i]);
    sort(all(vec));

    bool ok = false;
    if (get<2>(vec[0]) == 'R') ok = true;
    rep2(i, n - 1) {
        if (get<0>(vec[i - 1]) == get<0>(vec[i])) {
            if (ok && get<2>(vec[i]) == 'L') {
                puts("Yes");
                return 0;
            }
            else if (!ok && get<2>(vec[i]) == 'R') {
                ok = true;
            }
        }
        else {
            if (get<2>(vec[i]) == 'R') {
                ok = true;
            }
            else ok = false;
        }
    }
    puts("No");
}
