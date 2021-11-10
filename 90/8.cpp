#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
#define pi 3.14159265359;
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

int search(char c) {
    if (c == 'a') return 0;
    else if (c == 't') return 1;
    else if (c == 'c') return 2;
    else if (c == 'o') return 3;
    else if (c == 'd') return 4;
    else if (c == 'e') return 5;
    else if (c == 'r') return 6;
    return -1;
}

int main() {
    ll n;
    string s;
    cin >> n >> s;

    vvl dp(n, vl(7));
    rep(i, n) {
        if (i != 0) dp[i] = dp[i-1];

        ll sea = search(s[i]);
        if (sea == -1) continue;
        else if (i == 0 && sea != 0) continue;
        else if (sea == 0) dp[i][0]++;
        else {
            dp[i][sea] += dp[i-1][sea-1];
            dp[i][sea] %= 1000000007;
        }
    }

    cout << dp[n-1][6] << endl;
}