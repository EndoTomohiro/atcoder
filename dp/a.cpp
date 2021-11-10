#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    rep(i, n-1) {
        if (i != n-2) {
            int next2 = abs(h[i+2] - h[i]);
            dp[i+2] = dp[i] + next2;
        }

        if (i != 0) {
            int next = abs(h[i+1] - h[i]);
            dp[i+1] = min(dp[i+1], dp[i] + next);
        }
    }

    cout << dp[n-1] << endl;
}