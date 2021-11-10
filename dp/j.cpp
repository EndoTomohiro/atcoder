#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
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

int n;
vector<int> a(300);
vector< vector< vector<double> > > dp(301, vector< vector<double> >(301, vector<double>(301)));

double f(int i, int j, int k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if (i > 0) res += f(i-1, j, k) * i;
    if (j > 0) res += f(i+1, j-1, k) * j;
    if (k > 0) res += f(i, j+1, k-1) * k;
    res += n;
    res *= 1.0 / (i + j + k);

    return dp[i][j][k] = res;
}

int main() {
    cin >> n;

    vector<int> kosu(4);
    rep(i, n) {
        cin >> a[i];
        kosu[a[i]]++;
    }

    rep(i, 301) rep(j, 301) rep(k, 301) dp[i][j][k] = -1;

    cout << fixed << setprecision(10);

    cout << f(kosu[1], kosu[2], kosu[3]) << endl;
}