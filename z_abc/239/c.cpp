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

int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vl dx = {1, 2, 2, 1, -1, -2, -2, -1};
    vl dy = {2, 1, -1, -2, -2, -1, 1, 2};

    rep(i, 8) {
        ll x3 = x1 + dx[i];
        ll y3 = y1 + dy[i];
        if (abs(x3 - x2) == 2 && abs(y3 - y2) == 1 || abs(x3 - x2) == 1 && abs(y3 - y2) == 2) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
