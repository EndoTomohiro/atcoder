#include <bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int q;
    cin >> q;

    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        string x, y;
        cin >> x >> y;

        int lx = x.size();
        int ly = y.size();
        vector< vector<int> > dp(lx+1, vector<int>(ly+1));

        for (int i = 1; i <= lx; i++) {
            for (int j = 1; j <= ly; j++) {
                if (x[i-1] == y[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        ans[i] = dp[lx][ly];
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}