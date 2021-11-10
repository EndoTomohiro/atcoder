#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector< tuple<int, int, int> > abc(n);
    rep(i, n) cin >> get<0>(abc[i]) >> get<1>(abc[i]) >> get<2>(abc[i]);

    vector< tuple<int, int, int> > dp(n);
    get<0>(dp[0]) = get<0>(abc[0]);
    get<1>(dp[0]) = get<1>(abc[0]);
    get<2>(dp[0]) = get<2>(abc[0]);

    rep2(i, 1, n) {
        get<0>(dp[i]) = get<0>(abc[i]) + max(get<1>(dp[i-1]), get<2>(dp[i-1]));
        get<1>(dp[i]) = get<1>(abc[i]) + max(get<0>(dp[i-1]), get<2>(dp[i-1]));
        get<2>(dp[i]) = get<2>(abc[i]) + max(get<0>(dp[i-1]), get<1>(dp[i-1]));
    }

    int sum = max(max(get<0>(dp[n-1]), get<1>(dp[n-1])), get<2>(dp[n-1]));
    cout << sum << endl;
}