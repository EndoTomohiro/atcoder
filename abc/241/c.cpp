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
    vs s(n);
    rep(i, n) cin >> s[i];

    rep(i, n) rep(j, n) {
        if (i + 6 <= n) {
            ll c = 0;
            rep(k, 6) {
                if (s[i + k][j] == '#') c++;
            }
            if (c >= 4) {
                puts("Yes");
                return 0;
            }
        }
        if (j + 6 <= n) {
            ll c = 0;
            rep(k, 6) {
                if (s[i][j + k] == '#') c++;
            }
            if (c >= 4) {
                puts("Yes");
                return 0;
            }
        }
        if (i + 6 <= n && j + 6 <= n) {
            ll c = 0;
            rep(k, 6) {
                if (s[i + k][j + k] == '#') c++;
            }
            if (c >= 4) {
                puts("Yes");
                return 0;
            }
        }
        if (i - 5 >= 0 && j + 6 <= n) {
            ll c = 0;
            rep(k, 6) {
                if (s[i - k][j + k] == '#') c++;
            }
            if (c >= 4) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}
