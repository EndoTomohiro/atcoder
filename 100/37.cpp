#include <bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m), dp(n+1, 50000);
    for (int i = 0; i < m; i++) cin >> c[i];

    sort(c.begin(), c.end());

    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - c[i] >= 0) chmin(dp[j], dp[j-c[i]] + 1);
        }
    }

    cout << dp[n] << endl;
}