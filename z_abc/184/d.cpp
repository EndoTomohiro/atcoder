#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
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

double dp[101][101][101];

double f(ll a, ll b, ll c) {
    if (dp[a][b][c]) return dp[a][b][c];
    if (a == 100 || b == 100 || c == 100) return 0;
    double ans = 0;
    ans += (f(a + 1, b, c) + 1) * a / (a + b + c);
    ans += (f(a, b + 1, c) + 1) * b / (a + b + c);
    ans += (f(a, b, c + 1) + 1) * c / (a + b + c);
    dp[a][b][c] = ans;
    return ans;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(11);
    cout << f(a, b, c) << endl;
}
