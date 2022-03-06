#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
const double pi = 3.14159265359;
const ll INF = 500000000000000000;
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
    string s;
    ll q;
    cin >> s >> q;
    
    vc ans(q);
    rep(i, q) {
        ll t, k;
        cin >> t >> k;
        k--;
        ll len = 1, n = -1;
        rep(j, t) {
            if (len > INF) {
                n = 1;
                break;
                /*
                ll abc = 0, cnt = 0;
                while (k > 1) {
                    if (k % 2 == 0) abc++;
                    else abc--;
                    k = (k + 1) / 2;
                    cnt++;
                }
                abc -= max(0LL, t - cnt);
                abc %= 3;
                if (s[0] == 'A') {
                    if (abc == 0) ans[i] = 'A';
                    else if (abc == 1) ans[i] = 'B';
                    else ans[i] = 'C';
                }
                else if (s[0] == 'B') {
                    if (abc == 0) ans[i] = 'B';
                    else if (abc == 1) ans[i] = 'C';
                    else ans[i] = 'A';
                }
                else {
                    if (abc == 0) ans[i] = 'C';
                    else if (abc == 1) ans[i] = 'A';
                    else ans[i] = 'B';
                }
                continue;
                */
            }
            len *= 2;
        }
        if (n == -1) n = k / len + 1;
        k -= len * (n - 1);

        ll abc = 0, cnt = 0;
        while (k > 0) {
            if (k % 2 == 0) abc++;
            else abc--;
            if (abc < 0) abc += 3;
            cnt++;
            if (k == 1) break;
            k /= 2;
        }
        if (t - cnt) abc += t - cnt;
        abc %= 3;
        if (s[n - 1] == 'A') {
            if (abc == 0) ans[i] = 'A';
            else if (abc == 1) ans[i] = 'B';
            else ans[i] = 'C';
        }
        else if (s[n - 1] == 'B') {
            if (abc == 0) ans[i] = 'B';
            else if (abc == 1) ans[i] = 'C';
            else ans[i] = 'A';
        }
        else {
            if (abc == 0) ans[i] = 'C';
            else if (abc == 1) ans[i] = 'A';
            else ans[i] = 'B';
        }

    }

    rep(i, q) cout << ans[i] << endl;
}
