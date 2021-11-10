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

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<string> dp(k+1);

    rep(i, a[0]) dp[i] = "Second";

    for (int i : a) dp[i] = "First";

    rep(i, k+1) {
        if (dp[i] == "") {
            rep(j, n) {
                if (i - a[j] >= 0 && dp[i - a[j]] == "Second") {
                    dp[i] = "First";
                    break;
                }
            }
            if (dp[i] == "") dp[i] = "Second";
        }
    }

    cout << dp[k] << endl;
}