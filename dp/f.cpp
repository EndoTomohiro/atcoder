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

int main() {
    string s, t;
    cin >> s >> t;

    vector< vector<int> > dp(s.size()+1, vector<int>(t.size()+1));
    rep(i, s.size()+1) dp[i][0] = 0;
    rep(j, t.size()+1) dp[0][j] = 0;

    rep2(i, 1, s.size()+1) rep2(j, 1, t.size()+1) {
        if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

    int len = dp[s.size()][t.size()];
    int i = s.size()-1;
    int j = t.size()-1;

    string ans = "";

    while (len > 0) {
        if (s[i] == t[j]) {
            ans = s[i] + ans;
            i--;
            j--;
            len--;
        }

        else if (dp[i+1][j+1] == dp[i][j+1]) i--;

        else j--;
    }

    cout << ans << endl;
    
}