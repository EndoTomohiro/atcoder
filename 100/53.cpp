#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
const int inf = 1000100100;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define rep3(i, s, n) for (int i = (int)(n); i >= (int)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n, inf);

    rep(i, n) {
        int a;
        cin >> a;
        int less = lower_bound(all(dp), a) - dp.begin();
        dp[less] = a;
    }

    int ans = 0;
    rep(i, n) {
        if (dp[i] != inf) ans++;
        else break;
    }

    cout << ans << endl;
}