#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> dp(n);
    dp[0] = 0;
    
    rep(i, k) {
        if (i < n-1) dp[i+1] = abs(h[i+1] - h[0]);
    }

    rep2(i, 1, n-1) {
        if (i + k < n) {
            int nextk = abs(h[i+k] - h[i]);
            dp[i+k] = dp[i] + nextk;
        }

        rep2(j, 1, k) {
            if (i + j < n) {
                int nextj = abs(h[i+j] - h[i]);
                dp[i+j] = min(dp[i+j], dp[i] + nextj);
            }
        }
    }

    cout << dp[n-1] << endl;
}