#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
using ml = map<ll, ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll k;
    cin >> k;

    ll cnt = 0;
    vvl dp(20, vl(12));
    string ans;
    rep(i, 20) rep(j, 10) {
        if (!i) {
            dp[i][j] = 1;
            if (!j) continue;
        }
        else {
            if (!j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
        }
        if (cnt + dp[i][j] < k) {
            cnt += dp[i][j];
            continue;
        }
        ans += to_string(j);
        if (!i) {
            cout << ans << endl;
            return 0;
        }
        while (true) {
            if (i == 1) {
                ll ans0;
                if (j) ans0 = j + k - cnt - 2;
                else ans0 = j + k - cnt - 1;
                ans += to_string(ans0);
                cout << ans << endl;
                return 0;
            }
            if (j && cnt + dp[i - 1][j - 1] >= k) {
                i--; j--;
                ans += to_string(j);
                continue;
            } 
            if (j) cnt += dp[i - 1][j - 1];
            if (cnt + dp[i - 1][j] >= k) {
                i--;
                ans += to_string(j);
                continue;
            }
            cnt += dp[i - 1][j];
            i--; j++;
            ans += to_string(j);
        }
    }
}
