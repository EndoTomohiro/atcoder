#include <bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];

    vector< vector<int> > dp(n+1, vector<int>(w+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j - weight[i] >= 0) {
                chmax(dp[i+1][j], dp[i][j-weight[i]] + value[i]);
            }
            chmax(dp[i+1][j], dp[i][j]);
        }
    }

    cout << dp[n][w] << endl;
}
