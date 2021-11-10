#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

vector< vector<char> > a(1001, vector<char>(1001));
vector< vector<ll> > dp(1001, vector<ll>(1001));

ll powx(int a, int n) {
    int pow = 1;
    rep(i, n) {
        pow *= a;
    }
    return pow;
}

ll f(ll i, ll j) {
    if (a[i][j] == '#') return 0;

    else if (i == 1 && j == 1) return 1;

    else if (i == 1) return dp[i][j-1];

    else if (j == 1) return dp[i-1][j];

    else return (dp[i][j-1] + dp[i-1][j]) % (powx(10, 9) + 7);
}

int main() {
    int h, w;
    cin >> h >> w;

    rep2(i, 1, h+1) rep2(j, 1, w+1) {
        cin >> a[i][j];
        dp[i][j] = f(i, j);
    }

    cout << dp[h][w] << endl;
}